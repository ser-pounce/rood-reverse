# The battle script opcode system

Cutscenes, scripted events and some in-battle sequences are driven by byte-code scripts, run by the interpreter in `BATTLE.PRG` (handlers in `4DEA8.c`, the loop in `573B8.c`).

## Where scripts come from

An *event* is a script together with its strings, text box shapes and vibration patterns. A *scene* is what the player sees, which can span several events chained with opcode `0xF7`. Events start from one of three sources, chosen by the code that requests the event. Many are started by a *trigger*: an entry in the map's trigger table with conditions (the player on a tile, a flag value, an actor present and so on) that start either an EVT file or one of the map's triggered scripts.

| Source | Where the script is |
|---|---|
| EVT file | a file loaded from disc, started by a trigger, from another script, or, for EVT 0, when the player is defeated |
| Map entry script | the entry script in the map (MPD) file, usually run automatically when the map loads |
| Map triggered scripts | one of the additional scripts in the map, started by a trigger |

All three use the same layout:

| Offset | Size | Field |
|---|---|---|
| 0x00 | 2 | total size in bytes |
| 0x02 | 2 | offset of the string table |
| 0x04 | 2 | offset of the shape table (text box shapes) |
| 0x06 | 2 | offset of the vibration table |
| 0x08 | 8 | reserved, zero |
| 0x10 | … | **the script**, up to the string table |

## Running a script

`runScript` looks up the handler for each opcode and calls it. It is called once per frame for each running script.

Every handler has the same signature:

```c
int vs_battle_script_<opcode>_<name>(u_char* script, short slot);
```

- `script` points at the opcode and following operands.
- `slot` is the script slot that is running the opcode (see below), ost handlers ignore it.

The return value tells the interpreter what to do next:

| Value | Name | Meaning |
|---|---|---|
| 0 | `scriptNext` | Advance to the next opcode, and keep running within the same frame. |
| 1 | `scriptWait` | Not finished: stop for this frame and run the same opcode again next frame. |
| 2 | `scriptFinish` | The main script has finished, which ends the scene. |
| 3 | `scriptEnd` | Terminate this slot's script. |
| 4 | `scriptYield` | Advance to the next opcode, but stop for this frame and resume at the next one. |
| anything else | | The address of the opcode to continue at, used for jumps. |

## Script slots

Up to four scripts can run simultaneously. Slot 0 is the main script; slots 1 to 3 hold *forked* scripts.

- `0xF5` forks: the instructions that follow it are started in the given slot, and the current script jumps ahead past the forked block.
- `0xF6` ends the forked script when it reaches the end of its block.
- `0xF4` joins: it waits for or terminates the specified slot.

Slot 0 runs first each frame, then slots 1 to 3. Forked scripts only run while the main script is still active. When slot 0 returns `scriptFinish` the scene is over, unless an additional EVT file was queued with `0xF7`.

## Skipping a scene

A scene can contain *skippable sections*, which the player can skip by pressing START. They are delimited by three opcodes:

1. `0x0D` begins the section and marks it as skippable.
2. `0x0E` ends the body of the section. It is followed by a *skip handler*, ending in `0x0F`.
3. `0x0F` ends the skip handler.

If the section is not skipped, `0x0E` jumps over the skip handler. If START is pressed on slot 0 while the script is skippable, the interpreter switches to a second handler table, the *skip table*, and the rest of the body runs through it. In the skip table:

- opcodes that only draw or play something (text boxes, animations, sound effects) are replaced by `nop` or `yield`;
- opcodes that change the state of the game (flags, actor positions, spawning and despawning) keep their normal handlers, so the world ends up where it would have been;
- opcodes that make no sense while skipping stay as they are or are marked invalid.

Pressing START also clears pending text boxes and waits, stops the music if the section asked for it, and sets the `skippingScene` state flag. When `0x0E` is reached in skip mode it resets the effects that the skipped part started, clears the flag and returns to the normal table, so the skip handler that follows runs normally.

## Operand conventions

- In an operand table, *Byte* is the position within the instruction, counted from the opcode, which is byte 0. A range such as `1-2` is a little-endian 16 bit value.
- **Jump offsets** are 16 bit values counted from the address of the jump opcode itself. The loop opcode `0x4A` stores a positive distance and subtracts it to jump backwards.
- **Actor selectors** are 16 bit values. The top nibble selects the kind, the rest is the operand: `0x0nnn` finds the actor by id, `0x1nnn` names a slot in the battle actor table, and `0x2000` means *no actor* where one actor is expected and *all actors* where a list is expected.
- **State flags** are addressed by a 10 bit id. Three blocks of flags are cleared automatically: 16 event flags (0x10–0x1F) when an event starts, 32 map flags (0x20–0x3F) when a map loads, and 64 zone flags (0x40–0x7F) when a zone loads.
- Several opcodes share one handler because they differ only in the opcode byte, for example most of the camera opcodes between `0xC0` and `0xDB`. Instead of an operand table they have a table of sub-opcodes, with the operands written inline as `[n]`, numbered the same way.

## Opcode reference

*Len* is the instruction length in bytes. *Skipping* is the handler used while a section is being skipped, and `=` means the same handler.

### 0x0A–0x0F: Loading and skippable sections

| Opcode | Len | Handler | Skipping | Summary |
|---|---|---|---|---|
| 0x0A | 1 | `waitEvtLoad` | = | Waits until the event file that is being loaded, if any, has finished loading |
| 0x0C | 1 | `waitGimLoad` | = | Waits until the GIM that is being loaded has finished loading |
| 0x0D | 3 | `beginSkippable` | = | Begins a section of the script that the player can skip with START |
| 0x0E | 3 | `endSkippableBody` | = | Ends the body of a skippable section |
| 0x0F | 1 | `endSkipHandler` | = | Ends the skip handler of a skippable section |

<details>
<summary>Operands and details</summary>

#### 0x0D `beginSkippable`

| Byte | Meaning |
|---|---|
| 1 | bit 0 = keep the music playing if the section is skipped |
| 2 | unused |

#### 0x0E `endSkippableBody`

The skip handler follows, up to the 0F opcode. If the section was not skipped, jumps past the handler; if it was, finishes the skip and carries on into the handler.

| Byte | Meaning |
|---|---|
| 1-2 | offset from this opcode to jump to if the section was not skipped |

**Returns:** scriptYield if the section was skipped, otherwise the address to jump to.

#### 0x0F `endSkipHandler`

Only has an effect if the section was being skipped, in which case it finishes the skip like 0E.

</details>

### 0x10–0x1D: Text boxes, GIM images and text arguments

| Opcode | Len | Handler | Skipping | Summary |
|---|---|---|---|---|
| 0x10 | 11 | `initTextBox` | `nop` | Creates a text box at a fixed position on the screen |
| 0x11 | 4 | `showTextBox` | `nop` | Prints a string in a text box, and waits for it to be read unless told not to |
| 0x12 | 2 | `dismissTextBox` | = | Closes a text box |
| 0x13 | 9 | `initTextBoxNearActor` | `nop` | Creates a text box next to an actor, using the placement that fits on the screen |
| 0x14 | 2 | `dismissTextBoxAndWait` | `yield` | Closes a text box and waits until it has finished closing |
| 0x15 | 2 | `waitButtonPressed` | `yield` | Waits until one of the given buttons is pressed |
| 0x16 | 4 | `loadGim` | = | Loads a GIM image file |
| 0x17 | 6 | `showGimImage` | = | Shows an image of the loaded GIM, setting its position, scale and brightness |
| 0x18 | 7 | `tweenGimImage` | = | Smoothly changes a shown GIM image's position, scale and brightness |
| 0x19 | 1 | `unloadGim` | = | Unloads the GIM |
| 0x1A | 1 | `waitGimTweens` | `yield` | Waits until all the GIM image tweens have finished |
| 0x1B | 4 | `setPrintfArgInt` | = | Sets an integer argument of the printf-style text in the text boxes from state flags |
| 0x1C | 2 | `selectTextBox` | invalid | Lets the player choose between text boxes, and stores the choice in the first scratch flag |
| 0x1D | 2 | `setTextBoxAnimationDuration` | = | Sets the duration of a text box's animation |

<details>
<summary>Operands and details</summary>

#### 0x10 `initTextBox`

| Byte | Meaning |
|---|---|
| 1 | (parentBoxId << 4) \| boxId |
| 2-3 | flags/type (passed to arg1 of initTextBox) |
| 4 | x (in some unit, scaled *2 - 0x20) |
| 5 | y (scaled - 0x20) |
| 6 | width in characters |
| 7 | height in lines |
| 8-9 | speaker actor (actorSelectorNone: none) |
| 10 | speaker animation |

#### 0x11 `showTextBox`

| Byte | Meaning |
|---|---|
| 1 | boxId |
| 2 | string index |
| 3 | nonzero: do not wait for the player to advance the text |

#### 0x12 `dismissTextBox`

| Byte | Meaning |
|---|---|
| 1 | boxId |

#### 0x13 `initTextBoxNearActor`

| Byte | Meaning |
|---|---|
| 1 | boxId |
| 2-3 | actor to place the box next to (resolved by resolveActorId) |
| 4-5 | flags (passed to initTextBox); [5] & 0xF is the box shape, which also selects the placement preset |
| 6 | width in characters |
| 7 | height in lines |
| 8 | speaker animation |

#### 0x14 `dismissTextBoxAndWait`

| Byte | Meaning |
|---|---|
| 1 | boxId |

#### 0x15 `waitButtonPressed`

| Byte | Meaning |
|---|---|
| 1 | mask of pad buttons, only the low byte (L2, R2, L1, R1 and the face buttons) |

#### 0x16 `loadGim`

| Byte | Meaning |
|---|---|
| 1-2 | GIM index |
| 3 | first VRAM page slot |

#### 0x17 `showGimImage`

| Byte | Meaning |
|---|---|
| 1 | (image << 6) \| mode, image is 0-2 within the GIM and mode selects the draw function |
| 2 | x offset from the screen centre, signed, in units of 2 pixels |
| 3 | y offset from the screen centre, signed, in units of 2 pixels |
| 4 | scale, 0x20 is full size |
| 5 | brightness, 0x80 is normal |

#### 0x18 `tweenGimImage`

Waits first if the image is still being tweened.

| Byte | Meaning |
|---|---|
| 1 | x offset from the screen centre, signed, in units of 2 pixels |
| 2 | y offset from the screen centre, signed, in units of 2 pixels |
| 3 | target scale, 0x20 is full size |
| 4 | target brightness |
| 5 | (image << 6) \| curve, curve 0-3 are built in and 4-7 are set up by script |
| 6 | duration |

#### 0x1B `setPrintfArgInt`

| Byte | Meaning |
|---|---|
| 1 | printf argument integer to set (0-9) |
| 2-3 | state flag id in bits 0-9, type in bits 14-15: 0 = unsigned byte, 1 = signed byte, 2 = unsigned 16 bits, 3 = signed 16 bits. 2 and 3 read two sequential state flags. |

#### 0x1C `selectTextBox`

Waits until a choice is made.

| Byte | Meaning |
|---|---|
| 1 | mask of the text boxes to choose between, bit n is box n |

#### 0x1D `setTextBoxAnimationDuration`

| Byte | Meaning |
|---|---|
| 1 | (boxId << 5) \| animation duration (0-31) |

</details>

### 0x1E–0x3F: Actors

| Opcode | Len | Handler | Skipping | Summary |
|---|---|---|---|---|
| 0x1E | 4 | `actorDeath` | = | Kills an actor or a group of actors |
| 0x1F | 5 | `getActorTile` | = | Stores the tile an actor is standing on in state flags |
| 0x20 | 9 | `spawnActor` | = | Creates an actor from a model on a tile |
| 0x21 | 6 | `walkActorToTile` | = | Walks an actor to a tile, with pathfinding |
| 0x22 | 6 | `playAnimation` | `nop` | Plays an animation on an actor |
| 0x23 | 5 | `setActorFlags` | = | Sets the flags of an actor or a group of actors, including whether it is active (see setActorInactive) |
| 0x24 | 7 | `setActorSfxPanVolume` | = | Overrides the stereo pan and volume used for an actor's sound effects |
| 0x25 | 9 | `moveActorToTile` | = | Moves an actor to a tile and turns it to a facing, ignoring the tile map |
| 0x26 | 12 | `moveActorToCoordinate` | = | Like moveActorToTile, but to a position given in world coordinates instead of a tile |
| 0x27 | 7 | `slideActorToTile` | = | Slides an actor to a tile over time, ignoring the tile map |
| 0x28 | 10 | `slideActorToCoordinate` | = | Like slideActorToTile, but to a position given in world coordinates instead of a tile |
| 0x29 | 7 | `attachActor` | = | Attaches an actor to a bone of a parent actor |
| 0x2A | 7 | `walkActorToCoordinate` | = | Like walkActorToTile, but to a position given in world coordinates instead of a tile |
| 0x2B | 6 | `turnActorToFacing` | = | Turns an actor to face a direction |
| 0x2C | 6 | `turnActorToFaceActor` | = | Turns an actor to face the tile another actor is standing on |
| 0x2D | 7 | `turnActorToFaceTile` | = | Turns an actor to face a tile |
| 0x2E | 10 | `setActorScale` | = | Sets the scale of an actor, per axis |
| 0x2F | 3 | `despawnActor` | = | Removes actors, the counterpart of spawnActor |
| 0x30 | 6 | `waitActorActivity` | `yield` | Waits until the selected activities of an actor have finished |
| 0x31 | 6 | `setActorLightColor` | = | Overrides the ambient light colour of an actor |
| 0x32 | 6 | `queueAnimation` | `nop` | Queues an animation to play when the actor's current animation ends |
| 0x33 | 11 | `rotateActor` | = | Rotates an actor, either absolutely or relative to its current one |
| 0x34 | 8 | `setActorLookAngles` | = | Turns the actor's head to the given angles |
| 0x35 | 7 | `playAnimationFromFrame` | `nop` | Like playAnimation, but starts the animation part way through |
| 0x36 | 7 | `queueAnimationFromFrame` | `nop` | Like queueAnimation, but the queued animation starts part way through |
| 0x37 | 5 | `setActorMoveAnimation` | = | Sets the animation an actor plays while moving with moveActorToTile or moveActorToCoordinate |
| 0x38 | 6 | `setActorLookTarget` | = | Turns the actor's head towards another actor |
| 0x39 | 10 | `setActorLookPosition` | = | Turns the actor's head towards a world position |
| 0x3A | 4 | `enqueueEventData` | = | Enqueues event data: an event sequence (ESQ), which provides the animations in bank 1 of animationBankBase, and an event texture map (ETM), which holds facial animation frames |
| 0x3B | 1 | `waitDataQueueEmpty` | = | Waits until the object data queue is empty |
| 0x3C | 2 | `unloadEventData` | = | Unloads event data |
| 0x3D | 2 | `selectEventData` | = | Selects the slot of the loaded event data used by actors |
| 0x3E | 10 | `setActorEdgeHighlight` | = | Sets an edge highlight for an actor: a second copy of the actor in a flat colour, displaced and pushed back in the ordering table |
| 0x3F | 4 | `setWeaponDrawn` | = | Draws, sheathes or toggles the weapons of the selected actors |

<details>
<summary>Operands and details</summary>

#### 0x1E `actorDeath`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector, a single actor or a group |
| 3 | nonzero: play the death animation first, 0: start the fade-out directly |

#### 0x1F `getActorTile`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3-4 | first of three consecutive state flags that receive the actor's tile x, surface and z. The first flag is set to 0xFF if the actor does not exist. |

#### 0x20 `spawnActor`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector for the empty slot to create the actor in |
| 3-4 | model index (OBJ/xx.SHP), doubles as the id the actor is looked up by |
| 5-8 | tile to spawn on and facing: x, surface, z and facing (1/256 turn) |

#### 0x21 `walkActorToTile`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3 | tile x |
| 4 | unused |
| 5 | tile z |

#### 0x22 `playAnimation`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3 | animation index within the bank |
| 4 | unused |
| 5 | (bank << 6) \| blend frames, the bank selects the base id in animationBankBase |

#### 0x23 `setActorFlags`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3 | actor flags: bit 0 enabled, bit 1 visible, bit 2 frozen, bit 6 unknown |
| 4 | flags for the weapon models and the actor list: |
|  | bit 0: new flag value for the blade model |
|  | bit 1: leave the blade model's flag unchanged (ignores bit 0) |
|  | bit 2: new flag value for the shield model |
|  | bit 3: leave the shield model's flag unchanged (ignores bit 2) |
|  | bit 5: toggle actor deactivation |

#### 0x24 `setActorSfxPanVolume`

| Byte | Meaning |
|---|---|
| 1-2 | actor id |
| 3 | mode: |
|  | 0: clear the override, sounds follow the actor's position on screen |
|  | 1: use the pan and volume below, ramped over the duration. |
|  | 2: mute the actor's sounds |
| 4 | pan, 0x80 is centered |
| 5 | volume, 0x7F is maximum |
| 6 | ramp duration in frames, 0 applies immediately |

#### 0x25 `moveActorToTile`

Animated move (non-zero values for the frames) does not seem to be used by the scripts. Does not respect paths; walkActorToTile is used for walking in practice.

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3-5 | tile x, surface and z |
| 6 | final facing (1/256 turn). With frame counts, 0xFF skips the final turn; |
| 7 | movement frame count, 0 = immediately, 0xFF = default (from distance and the actor's unk5C2) |
| 8 | turn frame count, 0 = immediately, 0xFF = default (from angle and the actor's unk5C0) |

#### 0x26 `moveActorToCoordinate`

Does not respect paths; walkActorToCoordinate is used for walking in practice.

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3-4 | x in bits 1-15 (value >> 1). If bit 0 is set, x, y and z are added to the actor's current position instead of replacing it |
| 5-6 | y (height), 0x8000 = the ground height at the target (absolute only) |
| 7-8 | z |
| 9 | facing (1/256 turn), 0xFF = none: turn towards the direction of travel |
| 10 | movement frame count, 0 = immediately, 0xFF = default |
| 11 | turn frame count, 0 = immediately, 0xFF = default |

#### 0x27 `slideActorToTile`

Unlike moveActorToTile the actor only changes position, there is no walk animation and no turning.

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3-5 | tile x, surface and z |
| 6 | frame count, 0xFF = default (from distance and the actor's unk5C2) |

#### 0x28 `slideActorToCoordinate`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3-4 | x in bits 1-15 (value >> 1). If bit 0 is set, x, y and z are added to the actor's current position instead of replacing it |
| 5-6 | y (height) |
| 7-8 | z |
| 9 | frame count, 0xFF = default (from distance and the actor's unk5C2) |

#### 0x29 `attachActor`

A parent selector of actorSelectorNone detaches it.

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3-4 | parent actor selector |
| 5 | bone index in the parent |
| 6 | unused |

#### 0x2A `walkActorToCoordinate`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3-4 | x |
| 5-6 | z |

#### 0x2B `turnActorToFacing`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3 | facing (1/256 turn) |
| 4 | turn direction: 0 = shortest, 1 = positive, -1 = negative |
| 5 | frame count, 0 = immediately, 0xFF = default (from angle and the actor's unk5C0) |

#### 0x2C `turnActorToFaceActor`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3-4 | target actor selector |
| 5 | frame count, 0 = immediately, 0xFF = default (from angle and the actor's unk5C0) |

#### 0x2D `turnActorToFaceTile`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3-5 | tile x, surface and z |
| 6 | frame count, 0 = immediately, 0xFF = default (from angle and the actor's unk5C0) |

#### 0x2E `setActorScale`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3-4 | x scale (ONE = normal size) |
| 5-6 | y scale |
| 7-8 | z scale |
| 9 | frame count to change over, 0 = immediately |

#### 0x2F `despawnActor`

Enemies have their state saved and are not marked as hidden, so they return when the room is reloaded.

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |

#### 0x30 `waitActorActivity`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3-4 | mask of the vs_battle_getActorFlags bits to wait for |
| 5 | unused |

#### 0x31 `setActorLightColor`

Black (0, 0, 0) restores the colour taken from the map lighting at the actor's position.

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3-5 | red, green and blue (0x80 = neutral) |

#### 0x32 `queueAnimation`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3 | animation index within the bank |
| 4 | unused |
| 5 | (bank << 6) \| blend frames, as for playAnimation |

#### 0x33 `rotateActor`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3 | 0: rotate to the given absolute rotation, otherwise rotate by it |
| 4-5 | x rotation (1/ONE turn) |
| 6-7 | y rotation (the facing) |
| 8-9 | z rotation |
| 10 | frame count, 0 = immediately, 0xFF = default (from angle and the actor's unk5C0) |

#### 0x34 `setActorLookAngles`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3-4 | pitch (1/ONE turn) |
| 5-6 | yaw |
| 7 | speed, 0 = unlimited |

#### 0x35 `playAnimationFromFrame`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3 | animation index within the bank |
| 4 | frame to start at |
| 5 | unused |
| 6 | (bank << 6) \| blend frames |

#### 0x36 `queueAnimationFromFrame`

**Operands:** as for playAnimationFromFrame.

#### 0x37 `setActorMoveAnimation`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3 | animation bank, selects the base id in animationBankBase |
| 4 | animation index within the bank, 0xFF = the default |

#### 0x38 `setActorLookTarget`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3-4 | target actor selector, actorSelectorNone = stop looking at anything |
| 5 | speed, 0 = unlimited |

#### 0x39 `setActorLookPosition`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3-4 | x |
| 5-6 | y |
| 7-8 | z |
| 9 | speed, 0 = unlimited |

#### 0x3A `enqueueEventData`

| Byte | Meaning |
|---|---|
| 1-2 | event data id (E<id>.ESQ and E<id>.ETM) |
| 3 | bits 0-1: slot, bits 2-3: what to load (0 the ESQ, 1 the ESQ and then the ETM, 2 the ETM), bits 4-7: selects the VRAM slot of the ETM |

#### 0x3C `unloadEventData`

| Byte | Meaning |
|---|---|
| 1 | bits 0-1: slot, bit 2: unload only the ETM, otherwise the ESQ and its ETM |

#### 0x3D `selectEventData`

| Byte | Meaning |
|---|---|
| 1 | slot (1-3) |

#### 0x3E `setActorEdgeHighlight`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3-5 | offset x, y and z of the copy |
| 6 | number of ordering table entries to push the copy back |
| 7-9 | red, green and blue of the copy, all zero = no edge highlight |

#### 0x3F `setWeaponDrawn`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3 | 0 = sheathe, 1 = draw, 2 = toggle |

</details>

### 0x40–0x4F: Control flow

| Opcode | Len | Handler | Skipping | Summary |
|---|---|---|---|---|
| 0x40 | 6 | `jumpFwdUnlessFlagImm` | = | Continues if a state flag compares true against an immediate value, otherwise jumps |
| 0x41 | 6 | `jumpFwdUnlessFlag` | = | Continues if a state flag compares true against another state flag, otherwise jumps |
| 0x42 | 3 | `jumpFwdElse` | = | Jumps over the else branch, the opcode after it is always the target of a conditional jump (40, 41 or 47) |
| 0x43 | 1 | `nop` | = | Does nothing |
| 0x44 | 2 | `nop` | = | *as above* |
| 0x45 | 3 | `jumpFwd` | = | Presumably for jumping to a label |
| 0x46 | 3 | `switchOnFlag` | = | Starts a switch: stores the value of a state flag, for the jumpFwdCase opcodes that follow to compare against |
| 0x47 | 4 | `jumpFwdCase` | = | A case of a switch: jumps forward if the value stored by switchOnFlag matches |
| 0x48 | 1 | `endSceneReset` | `nop` | Ends sceneResetScript |
| 0x49 | 3 | `setLoopCounter` | = | Sets a loop counter |
| 0x4A | 4 | `loopCondition` | = | Checks a loop condition and jumps back accordingly |
| 0x4B | 3 | `break` | = | Breaks out of a loop, jumping past the loopCondition that closes the loop |
| 0x4C | 3 | `jumpFwdUnused` | = | Not used by any event script |

<details>
<summary>Operands and details</summary>

#### 0x40 `jumpFwdUnlessFlagImm`

| Byte | Meaning |
|---|---|
| 1 | comparison in the high nibble (flagComparison*), bits 6-9 of the flag id in the low nibble |
| 2 | bits 0-5 of the flag id in bits 2-7 |
| 3 | value to compare with (signed) |
| 4-5 | offset from this opcode to jump to if the comparison is false |

#### 0x41 `jumpFwdUnlessFlag`

Like jumpFwdUnlessFlagImm, but the value to compare with is a state flag (also there is no AND op)

| Byte | Meaning |
|---|---|
| 1 | comparison in the high nibble (flagComparison*), bits 6-9 of the first flag id in the low nibble |
| 2 | bits 0-5 of the first flag id in bits 2-7, bits 8-9 of the second flag id in bits 0-1 |
| 3 | bits 0-7 of the second flag id |
| 4-5 | offset from this opcode to jump to if the comparison is false |

#### 0x42 `jumpFwdElse`

| Byte | Meaning |
|---|---|
| 1-2 | target offset from this opcode |

#### 0x45 `jumpFwd`

| Byte | Meaning |
|---|---|
| 1-2 | target offset from this opcode |

#### 0x46 `switchOnFlag`

| Byte | Meaning |
|---|---|
| 1-2 | state flag id |

#### 0x47 `jumpFwdCase`

| Byte | Meaning |
|---|---|
| 1 | value to compare |
| 2-3 | target offset from this opcode |

#### 0x49 `setLoopCounter`

Using 0xFF as the counter is a marker for the start of an infinite loop.

| Byte | Meaning |
|---|---|
| 1 | counter index (0-15), 0xFF = none |
| 2 | number of times to loop |

#### 0x4A `loopCondition`

| Byte | Meaning |
|---|---|
| 1 | counter index (0-15), 0xFF = unconditional jump back (i.e. infinite loop) |
| 2-3 | target offset before this opcode |

#### 0x4B `break`

| Byte | Meaning |
|---|---|
| 1-2 | target offset from this opcode |

#### 0x4C `jumpFwdUnused`

| Byte | Meaning |
|---|---|
| 1-2 | target offset from this opcode |

</details>

### 0x50–0x5F: Flags, UI, timers and easing

| Opcode | Len | Handler | Skipping | Summary |
|---|---|---|---|---|
| 0x50 | 4 | `modifyFlagImm` | = | Modifies a state flag using an immediate value: the flag is replaced by the result of `flag <operation> value` |
| 0x51 | 4 | `modifyFlag` | = | Like modifyFlagImm, but the value is another state flag, and there are two more operations: absolute difference and swap |
| 0x52 | 5 | `setFlagToItemCount` | = | Gets the count of a given item |
| 0x53 | 3 | `forgetZoneEnemies` | = | Forgets the saved state of the enemies of a zone and map, so they are in their initial state the next time it is loaded (see despawnActor, which saves it) |
| 0x54 | 4 | `playWeaponSfx` | `nop` | Plays the sound of an actor drawing or sheathing its weapon, without changing its weapon state |
| 0x55 | 2 | `setActorsAwake` | = | Wakes every actor except actor 0 (the player), or puts them all into the dormant state: inert, no AI, not targetable (see setActorAwake) |
| 0x56 | 3 | `setFlagToButtons` | = | Stores the pad state of the first controller in a state flag |
| 0x57 | 4 | `fullyRestoreActor` | = | Fully restores an actor: HP, MP and every limb's HP to their maximums, risk and action delay to 0, and all status effects removed |
| 0x58 | 2 | `setUiVisible` | = | Shows or hides the UI (HP, MP and risk bars, limb and status panel) and the minimap |
| 0x59 | 4 | `openMenu` | = | Opens a menu and waits for it to finish |
| 0x5A | 7 | `setBattleTimer` | = | Starts or stops the on-screen timer |
| 0x5B | 4 | `setTextBoxSpeaker` | = | Sets which actor speaks a text box and their animation |
| 0x5C | 7 | `setActorWeaponModels` | = | Changes the weapon models an actor holds |
| 0x5D | 4 | `setActorSway` | = | Gives an actor a slight swaying motion |
| 0x5E | 3 | `waitFramesOrButton` | `yield` | Waits for a number of frames, or until one of the given buttons is pressed |
| 0x5F | 2 | `defineEasing` | = | Defines one of the four easing curves, numbered 4-7, that tweens can use |

<details>
<summary>Operands and details</summary>

#### 0x50 `modifyFlagImm`

| Byte | Meaning |
|---|---|
| 1 | operation in the high nibble (flagOperation*, up to Assign), bits 6-9 of the flag id in the low nibble |
| 2 | bits 0-5 of the flag id in bits 2-7 |
| 3 | value |

#### 0x51 `modifyFlag`

| Byte | Meaning |
|---|---|
| 1 | operation in the high nibble (flagOperation*), bits 6-9 of the first flag id in the low nibble |
| 2 | bits 0-5 of the first flag id in bits 2-7, bits 8-9 of the second flag id in bits 0-1 |
| 3 | bits 0-7 of the second flag id |

#### 0x52 `setFlagToItemCount`

| Byte | Meaning |
|---|---|
| 1-2 | item id |
| 3-4 | state flag id |

#### 0x53 `forgetZoneEnemies`

| Byte | Meaning |
|---|---|
| 1 | zone id (ZND) |
| 2 | map id (MPD) |

#### 0x54 `playWeaponSfx`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3 | 0 = draw, 1 = sheathe |

#### 0x55 `setActorsAwake`

| Byte | Meaning |
|---|---|
| 1 | 0 = dormant, nonzero = awake |

#### 0x56 `setFlagToButtons`

Only the low byte of the pad is read: L2, R2, L1, R1, triangle, circle, cross and square.

| Byte | Meaning |
|---|---|
| 1-2 | bits 0-9: state flag id, bit 15: 1 = buttons newly pressed this frame, 0 = buttons held |

#### 0x57 `fullyRestoreActor`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3 | unused |

#### 0x58 `setUiVisible`

| Byte | Meaning |
|---|---|
| 1 | 0 = hide, 1 = show |

#### 0x59 `openMenu`

Values 10-14 open MENUF.PRG (not really a menu: it shows the cube puzzle and boss time attack screens, selected by state flag menuFSubmenu); 15 opens the loot or unlock screens; any other value opens the menu screen with that id.

| Byte | Meaning |
|---|---|
| 1 | menu selector |
| 2-3 | unused |

#### 0x5A `setBattleTimer`

| Byte | Meaning |
|---|---|
| 1 | 0 = stop and clear the timer, nonzero = start |
| 2 | lifetime index (see startBattleTimer) |
| 3 | mode index, 0 = counts up, 1 = counts down |
| 4-6 | hours, minutes and seconds to count down from |

#### 0x5B `setTextBoxSpeaker`

| Byte | Meaning |
|---|---|
| 1 | box id in the low nibble, speaker animation in the high nibble |
| 2-3 | actor selector, or actorSelectorNone for no speaker |

#### 0x5C `setActorWeaponModels`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3 | blade model id, 0 = none, 0xFF = leave unchanged, 0xFE = take both weapons from the actor's equipment |
| 4 | unused |
| 5 | shield model id, 0 = none, 0xFF = leave unchanged |
| 6 | unused |

#### 0x5D `setActorSway`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3 | sway angle at its peak, in 1/ONE of a full turn, 0 = stop swaying |

#### 0x5E `waitFramesOrButton`

| Byte | Meaning |
|---|---|
| 1 | mask of pad buttons, only the low byte (L2, R2, L1, R1 and the face buttons) |
| 2 | frames to wait, must not be 0 |

#### 0x5F `defineEasing`

It is one of the built-in curves 0-3 with its progress squared a number of times first.

| Byte | Meaning |
|---|---|
| 1 | (slot << 6) \| (base curve << 4) \| squarings, where squarings is a signed 4 bit number, an ease-in if positive and an ease-out if negative |

</details>

### 0x60–0x7F: World: geometry, transitions, backgrounds and particles

| Opcode | Len | Handler | Skipping | Summary |
|---|---|---|---|---|
| 0x60 | 3 | `setCloudstoneMoving` | = | Starts or stops a cloudstone |
| 0x61 | 3 | `overrideFogDepth` | = | Sets the depth beyond which polygons are dimmed, overriding current setting |
| 0x62 | 2 | `setFirstPersonRendering` | = | Enables or disables the close-up render mode used for first person view, which subdivides large polygons, renders geometry usually culled in 3rd person view, and skips geometry flagged as hidden in first person |
| 0x63 | 1 | `statusUnk` | = | Clears no statuses (empty mask), so it has no effect |
| 0x64 | 2 | `showGeometry` | = | Shows a room geometry object |
| 0x65 | 2 | `hideGeometry` | = | Hides a room geometry object |
| 0x66 | 3 | `swapGeometryFlags` | = | Swaps the render flags of two room geometry objects |
| 0x67 | 5 | `setTileBlocked` | = | Blocks or unblocks a tile in the room's walkable area |
| 0x68 | 10 | `warp` | = | Warps the player to another room with a screen transition, waiting until it has loaded |
| 0x69 | 4 | `screenTransitionOut` | `nop` | Transitions the screen out with a fade or wipe, waiting for it to finish |
| 0x6A | 4 | `screenTransitionIn` | `nop` | Transitions the screen back in from a fade or wipe, without waiting for it to finish |
| 0x6B | 2 | `setScreenTransitionWipeAngle` | = | Sets the wipe angle of the screen transition, without starting one |
| 0x6C | 4 | `setScreenTransition` | = | Sets the effect, speed and wipe angle of the screen transition, without starting one |
| 0x6D | 2 | `setSceneVisibility` | `nop` | Switches the screen, the room and the actors on or off |
| 0x6E | 1 | `waitForScreenTransition` | `yield` | Waits until the screen transition has finished |
| 0x6F | 2 | `setUnk` | = | Turns something unknown on (nonzero operand) or off |
| 0x70 | 8 | `transformColors` | = | Adds a colour offset to the palettes of actors, the scene or the background, either at once or over a few frames |
| 0x71 | 4 | `fadeActor` | = | Fades an actor out or in with a flash |
| 0x72 | 3 | `drawSheatheAshleyWeapon` | = | Makes Ashley draw or sheathe his weapon, waiting for the animation to finish |
| 0x73 | 2 | `setBackgroundVisible` | = | Shows or hides the background texture |
| 0x74 | 2 | `loadBackground` | = | Starts loading the room's background image into a texture page slot |
| 0x75 | 1 | `waitBackgroundLoad` | = | Waits until the background image started by opcode 74 has finished loading |
| 0x76 | 1 | `unloadBackground` | = | Hides the background image and frees its texture page(s) |
| 0x77 | 5 | `setParticleEffect` | = | Sets the particle effect, either at once or ramping over a number of frames |
| 0x78 | 2 | `freezeParticleEffect` | = | Stops or resumes the particle effect drifting within the room's limits |
| 0x79 | 3 | `controlRoomTask` | = | Starts a room task, or pauses and resumes it |
| 0x7A | 2 | `setParticleEffectSoundScripted` | = | Acquires or relinquishes control of the particle effect sound, such as the rain loop |
| 0x7B | 5 | `setBackgroundOffset` | = | Offsets the background image loaded by opcode 74, in pixels |
| 0x7C | 2 | `cullOccludingGeometry` | = | Culls room geometry that occludes the view depending on the camera angle |
| 0x7D | 3 | `adjustGeometryDepth` | = | Offsets the ordering table position of a geometry object |
| 0x7E | 4 | `setBackgroundParallax` | = | Sets how far the background image shifts as the camera turns and tilts |

<details>
<summary>Operands and details</summary>

#### 0x60 `setCloudstoneMoving`

| Byte | Meaning |
|---|---|
| 1 | index of the cloudstone in the room data |
| 2 | 1 = moving, 0 = stopped |

#### 0x61 `overrideFogDepth`

| Byte | Meaning |
|---|---|
| 1-2 | depth, with bit 15 toggling the override |

#### 0x62 `setFirstPersonRendering`

| Byte | Meaning |
|---|---|
| 1 | 1 = enabled, 0 = disabled |

#### 0x63 `statusUnk`

Probably unused.

#### 0x64 `showGeometry`

| Byte | Meaning |
|---|---|
| 1 | geometry object id |

#### 0x65 `hideGeometry`

| Byte | Meaning |
|---|---|
| 1 | geometry object id |

#### 0x66 `swapGeometryFlags`

| Byte | Meaning |
|---|---|
| 1 | first geometry object id |
| 2 | second geometry object id |

#### 0x67 `setTileBlocked`

| Byte | Meaning |
|---|---|
| 1 | tile column |
| 2 | layer, 0 or 1 = layer of the tile grid, 2 and above = cloudstone (layer - 2) |
| 3 | tile row |
| 4 | 1 = blocked, 0 = open |

#### 0x68 `warp`

| Byte | Meaning |
|---|---|
| 1 | zone, 0 = the current zone |
| 2 | map within the zone |
| 3 | tile column |
| 4 | arrival surface |
| 5 | tile row |
| 6 | facing |
| 7 | bit 0 walk forward, bit 1 face the camera, bit 2 continue script in the new room (otherwise the event ends), bit 3 switch to the new zone's music |
| 8 | screen transition effect |
| 9 | screen transition speed |

#### 0x69 `screenTransitionOut`

| Byte | Meaning |
|---|---|
| 1 | effect |
| 2 | speed |
| 3 | wipe angle, in 1/256ths of a turn |

#### 0x6A `screenTransitionIn`

| Byte | Meaning |
|---|---|
| 1 | effect |
| 2 | speed |
| 3 | wipe angle, in 1/256ths of a turn |

#### 0x6B `setScreenTransitionWipeAngle`

Unused.

| Byte | Meaning |
|---|---|
| 1 | wipe angle, in 1/256ths of a turn |

#### 0x6C `setScreenTransition`

| Byte | Meaning |
|---|---|
| 1 | effect |
| 2 | speed |
| 3 | wipe angle, in 1/256ths of a turn |

#### 0x6D `setSceneVisibility`

Each takes a 2-bit field of the operand, 0 = off, 1 = on, 2 or 3 = leave as is.

| Byte | Meaning |
|---|---|
| 1 | bits 0-1 screen output, bits 2-3 room geometry, bits 4-5 all actors |

#### 0x6F `setUnk`

Both handlers are empty, so it has no effect. Only used with [1] = 0xF6, in events 5, 14 and 15.

#### 0x70 `transformColors`

| Byte | Meaning |
|---|---|
| 1 | target in the high nibble, 0 = actors, 1 = scene, 2 = background, and the colour transform mode in the low nibble, 8 = restore the original colours |
| 2-3 | actors to transform, if the target is actors |
| 4 | duration in frames as a power of two, 0 to 4, anything higher is instant |
| 5-7 | signed red, green and blue offsets |

#### 0x71 `fadeActor`

Used in cutscenes when an actor teleports.

| Byte | Meaning |
|---|---|
| 1-2 | actor |
| 3 | 1 fades out, 2 fades in. 0 is not used by any script (renders invisible). |

#### 0x72 `drawSheatheAshleyWeapon`

Does nothing if his weapon was not drawn when the event began (state flag 0xAC). Cutscenes sheathe at the start and draw again at the end.

| Byte | Meaning |
|---|---|
| 1 | 0 sheathes, 1 draws |
| 2 | 0 changes at once, 1 plays the quick animation the player uses, 2 plays a slower one seen only in cutscenes |

#### 0x73 `setBackgroundVisible`

| Byte | Meaning |
|---|---|
| 1 | 0 == hide, !0 == show |

#### 0x74 `loadBackground`

| Byte | Meaning |
|---|---|
| 1 | texture page slot |

#### 0x77 `setParticleEffect`

The values are only a starting point, as they then drift within the limits set by the room.

| Byte | Meaning |
|---|---|
| 1 | effect in the high nibble (0 none, 1 rain, 2 snow, 3 heavy snow, 4 dark particles rising from the floor), intensity in the low nibble |
| 2 | direction the particles are blown, 256 steps per turn |
| 3 | fall angle, 0x80 falls straight down |
| 4 | 0 sets the values at once, otherwise the number of frames to blend over |

#### 0x78 `freezeParticleEffect`

| Byte | Meaning |
|---|---|
| 1 | 1 stops the drift, 0 resumes it |

#### 0x79 `controlRoomTask`

Room tasks run every frame, animating textures, moving geometry objects and playing the room's sounds. Some start running when the room loads.

| Byte | Meaning |
|---|---|
| 1 | 0 starts the task (if the same task is already executing it is completed first), 1 pauses or resumes |
| 2 | task index, with the room's scripted tasks starting at 0x40 |

#### 0x7A `setParticleEffectSoundScripted`

Scripts must call this before using 0x80 with bank 2.

| Byte | Meaning |
|---|---|
| 1 | !0 acquires control, 0 returns control |

#### 0x7B `setBackgroundOffset`

| Byte | Meaning |
|---|---|
| 1-2 | horizontal offset (signed) |
| 3-4 | vertical offset (signed) |

#### 0x7C `cullOccludingGeometry`

Usually disabled and renabled at the start and end of cutscenes.

| Byte | Meaning |
|---|---|
| 1 | 0 renders all geometry, anything else culls by camera angle |

#### 0x7D `adjustGeometryDepth`

Can be undone by negating the original amount.

| Byte | Meaning |
|---|---|
| 1 | geometry object index |
| 2 | amount to add (signed) |

#### 0x7E `setBackgroundParallax`

| Byte | Meaning |
|---|---|
| 1 | shift for horizontal turning (signed) |
| 2 | shift for vertical tilting (signed) |
| 3 | unused |

</details>

### 0x80–0x9F: Sound effects and music

| Opcode | Len | Handler | Skipping | Summary |
|---|---|---|---|---|
| 0x80 | 5 | `playSfx` | `nop` | Plays a sound effect |
| 0x81 | 4 | `playActorSfx` | `nop` | Plays one of an actor's sound effects |
| 0x82 | 5 | `fadeSfxVolume` | `nop` | Fades a sound effect to a volume |
| 0x83 | 1 | `stopAllSfx` | = | Stops all sound effects |
| 0x84 | 3 | `stopSfx` | = | Stops a sound effect |
| 0x85 | 3 | `loadSfxSlot` | = | Starts loading a sound effect file from disc into a slot |
| 0x86 | 2 | `waitSfxLoad` | = | Waits until the sound effect file being loaded into a slot by opcode 85 is ready |
| 0x87 | 2 | `freeSfx` | = | Stops the sounds from a slot's sound effect file and unloads it |
| 0x88 | 2 | `setCurrentSfx` | = | Selects the loaded sound effect slot that sound group 3 plays from |
| 0x89 | 1 | `loadAreaMusic` | = | Starts loading the area's music into music slot 3, along with its instrument bank |
| 0x8F | 5 | `crossfadeMusic` | `nop` | Fades out the current script music and fades in the music in another slot |
| 0x90 | 3 | `loadMusicSlot` | = | Starts loading a music track from disc into a music slot |
| 0x91 | 2 | `freeMusic` | = | Stops the music in a slot and unloads it |
| 0x92 | 4 | `playMusic` | `nop` | Plays the music in a slot |
| 0x93 | 3 | `fadeMusicVolume` | `nop` | Fades the script music's volume |
| 0x94 | 3 | `rampMusicTempo` | `nop` | Ramps the script music's tempo |
| 0x95 | 3 | `rampMusicPitch` | `nop` | Ramps the script music's pitch |
| 0x96 | 1 | `stopMusic` | `nop` | Stops the script music |
| 0x97 | 2 | `waitMusicSilent` | `nop` | Waits until the music in a slot has faded to silence |
| 0x98 | 1 | `pushMusicState` | `nop` | Saves a copy of the playing music's state |
| 0x99 | 2 | `waitMusicLoad` | = | Waits until the music being loaded into a slot by opcode 90 is ready |
| 0x9A | 3 | `waitMusicBar` | `yield` | Waits until the music has played up to a bar |
| 0x9B | 5 | `rampSfxPitch` | `nop` | Ramps a sound effect's pitch |
| 0x9C | 5 | `rampSfxPan` | `nop` | Ramps a sound effect's pan |
| 0x9D | 2 | `loadInstrumentBank` | = | Starts loading the instrument bank a music track plays with, unless it is already loaded |
| 0x9E | 1 | `waitInstrumentBankLoad` | = | Waits until the instrument bank started by opcode 9D or 89 is loaded and ready |
| 0x9F | 2 | `queueMusic` | `nop` | Queues the script music to start once the current music reaches its end |

<details>
<summary>Operands and details</summary>

#### 0x80 `playSfx`

Group 2 is ignored unless opcode 7A has taken control of the particle effect sound.

| Byte | Meaning |
|---|---|
| 1 | sound group: 1 = general sound effects, 2 = the particle effect sound, 3 = effects from the bank selected by opcode 88 |
| 2 | sound ID, or the index within the bank for group 3 |
| 3 | pan, 0x80 is centre |
| 4 | volume, up to 0x7F |

#### 0x81 `playActorSfx`

| Byte | Meaning |
|---|---|
| 1-2 | actor ID |
| 3 | sound effect type |

#### 0x82 `fadeSfxVolume`

An ID of 0 fades every sound in the group.

| Byte | Meaning |
|---|---|
| 1 | sound group, as in opcode 80 |
| 2 | sound ID |
| 3 | target volume |
| 4 | fade duration |

#### 0x84 `stopSfx`

An ID of 0 stops every sound in the group.

| Byte | Meaning |
|---|---|
| 1 | sound group, as in opcode 80 |
| 2 | sound ID |

#### 0x85 `loadSfxSlot`

Opcode 86 waits for the load to finish.

| Byte | Meaning |
|---|---|
| 1 | sound effect file ID |
| 2 | slot, 1 to 3 |

#### 0x86 `waitSfxLoad`

| Byte | Meaning |
|---|---|
| 1 | slot, 1 to 3 |

#### 0x87 `freeSfx`

| Byte | Meaning |
|---|---|
| 1 | slot, 1 to 3 |

#### 0x88 `setCurrentSfx`

| Byte | Meaning |
|---|---|
| 1 | slot, 1 to 3 |

#### 0x89 `loadAreaMusic`

Scripts use it to bring the area music back after a cutscene track.

#### 0x8F `crossfadeMusic`

| Byte | Meaning |
|---|---|
| 1 | music slot to play |
| 2 | volume |
| 3 | fade in duration |
| 4 | fade out duration |

#### 0x90 `loadMusicSlot`

Opcode 99 waits for the load to finish.

| Byte | Meaning |
|---|---|
| 1 | music ID |
| 2 | slot, 1 to 4 |

#### 0x91 `freeMusic`

| Byte | Meaning |
|---|---|
| 1 | slot, 1 to 4 |

#### 0x92 `playMusic`

| Byte | Meaning |
|---|---|
| 1 | slot, 1 to 4 |
| 2 | volume |
| 3 | fade duration |

#### 0x93 `fadeMusicVolume`

| Byte | Meaning |
|---|---|
| 1 | target volume |
| 2 | fade duration |

#### 0x94 `rampMusicTempo`

| Byte | Meaning |
|---|---|
| 1 | target tempo adjustment (signed), 0 leaves the tempo unchanged, negative is slower and positive is faster |
| 2 | ramp duration |

#### 0x95 `rampMusicPitch`

| Byte | Meaning |
|---|---|
| 1 | target pitch (signed) |
| 2 | ramp duration |

#### 0x97 `waitMusicSilent`

| Byte | Meaning |
|---|---|
| 1 | slot, 1 to 4 |

#### 0x99 `waitMusicLoad`

| Byte | Meaning |
|---|---|
| 1 | slot, 1 to 4 |

#### 0x9A `waitMusicBar`

| Byte | Meaning |
|---|---|
| 1-2 | bar number |

#### 0x9B `rampSfxPitch`

An ID of 0 ramps every sound in the group.

| Byte | Meaning |
|---|---|
| 1 | sound group, as in opcode 80 |
| 2 | sound ID |
| 3 | target pitch (signed) |
| 4 | ramp duration |

#### 0x9C `rampSfxPan`

An ID of 0 ramps every sound in the group.

| Byte | Meaning |
|---|---|
| 1 | sound group, as in opcode 80 |
| 2 | sound ID |
| 3 | target pan, 0x80 is centre |
| 4 | ramp duration |

#### 0x9D `loadInstrumentBank`

Opcode 9E waits for it to be ready.

| Byte | Meaning |
|---|---|
| 1 | music ID |

#### 0x9F `queueMusic`

| Byte | Meaning |
|---|---|
| 1 | slot, 1 to 4 |

</details>

### 0xA0–0xAF: Effects and actor trails

| Opcode | Len | Handler | Skipping | Summary |
|---|---|---|---|---|
| 0xA0 | 5 | `startEffect` | = | Loads and starts a visual effect (EFFECT/E###.P: sprites, particles, camera and sound, as used for spell animations) targeting an actor |
| 0xA1 | 2 | `triggerEffectStage` | = | Starts one stage of the visual effect |
| 0xA2 | 2 | `waitEffectState` | = | Waits until the visual effect system is in the given state |
| 0xA3 | 1 | `yieldIfSkipping` | = | Yields for a frame while skipping, otherwise does nothing |
| 0xA4 | 1 | `waitEffectStageReady` | = | Waits until the visual effect is loaded and has stages left to trigger |
| 0xA5 | 1 | `cancelEffect` | = | Cancels the running visual effect and waits until the effect system is idle or waiting for a stage to be triggered |
| 0xA6 | 2 | `rearmEffectStage` | = | Makes a stage that was already triggered available to trigger again |
| 0xA8 | 2 | `setMusicTargetCue` | = | Sets the cue the playing music should reach |
| 0xA9 | 2 | `playVibration` | `nop` | Starts a controller vibration pattern from the script's pattern table, or stops vibration |
| 0xAA | 5 | `setActorTrail` | = | Starts or stops a motion trail following one of an actor's bones |

<details>
<summary>Operands and details</summary>

#### 0xA0 `startEffect`

Its stages are started by opcode A1.

| Byte | Meaning |
|---|---|
| 1-2 | effect ID |
| 3-4 | target actor |

#### 0xA1 `triggerEffectStage`

When skipping, cancels the effect instead.

| Byte | Meaning |
|---|---|
| 1 | stage index |

#### 0xA2 `waitEffectState`

Scripts use it to wait for the effect to finish, or to be ready for its next stage. Skipping cancels the effect first.

| Byte | Meaning |
|---|---|
| 1 | state to wait for |

#### 0xA3 `yieldIfSkipping`

**Operands:** none.

#### 0xA4 `waitEffectStageReady`

**Operands:** none.

#### 0xA5 `cancelEffect`

**Operands:** none.

#### 0xA6 `rearmEffectStage`

| Byte | Meaning |
|---|---|
| 1 | stage index |

#### 0xA8 `setMusicTargetCue`

The music does not jump at once, but takes its own route there at its next branch point.

| Byte | Meaning |
|---|---|
| 1 | cue |

#### 0xA9 `playVibration`

Adding 8 to the index copies the pattern before playing.

| Byte | Meaning |
|---|---|
| 1 | pattern index, or 0xFF to stop vibration |

#### 0xAA `setActorTrail`

Stopping fades out every active trail, not only the actor's.

| Byte | Meaning |
|---|---|
| 1 | 1 to start, 0 to stop |
| 2-3 | actor |
| 4 | bone |

</details>

### 0xB0–0xBF: Scene commands and screen effects

| Opcode | Len | Handler | Skipping | Summary |
|---|---|---|---|---|
| 0xB1 | 2 | `setEnteredDoor` | = | Overrides which door the player entered the room through |
| 0xB2 | 8 | `setFlagsToActorDistanceAndAngle` | = | Stores the distance and angle between two actors in two consecutive state flags |
| 0xB3 | 4 | `setActorAwake` | = | Wakes the selected actors, or puts them into the dormant state |
| 0xB4 | 7 | `showMiscLoot` | invalid | Shows the loot screen with up to two consumable or key items and waits for it to close |
| 0xB5 | 3 | `removeMiscItem` | = | Removes one of a misc item from the inventory |
| 0xB6 | 7 | `setFlagToActorDistance` | = | Stores the distance between two actors, in whole tiles, in a state flag |
| 0xB7 | 6 | `specialOp` | = | Runs one of a set of miscellaneous scene commands, chosen by the sub-opcode |
| 0xB8 | 1 | `waitScreenEffectsLoaded` | = | Waits until the screen effects overlay, started by opcode BC, has finished loading |
| 0xB9 | 3 | `framebufferEffectParams` | = | Sets the parameters of the frame buffer effect and the lens distortion |
| 0xBA | 2 | `framebufferEffectParams` | = | *as above* |
| 0xBB | 3 | `setScreenBlur` | `nop` | Blurs the screen from a given depth in the drawing order, or turns the blur off |
| 0xBC | 1 | `loadScreenEffects` | = | Starts loading the screen effects overlay (SCREFF2.PRG) |
| 0xBD | 2 | `nop` | = | Does nothing |
| 0xBE | 1 | `unloadScreenEffects` | = | Releases the screen effects overlay |
| 0xBF | 3 | `framebufferEffectParams` | = | *as above* |

<details>
<summary>Operands and details</summary>

#### 0xB1 `setEnteredDoor`

| Byte | Meaning |
|---|---|
| 1 | door index |

#### 0xB2 `setFlagsToActorDistanceAndAngle`

| Byte | Meaning |
|---|---|
| 1-2 | first actor |
| 3-4 | second actor |
| 5 | distance scale |
| 6-7 | state flag id for the distance, the angle is placed in the following flag |

#### 0xB3 `setActorAwake`

| Byte | Meaning |
|---|---|
| 1-2 | actor selector |
| 3 | 0 = dormant, nonzero = awake |

#### 0xB4 `showMiscLoot`

An item id of 0 leaves that item out. No script uses this opcode.

| Byte | Meaning |
|---|---|
| 1-2 | first item id |
| 3 | first item count |
| 4-5 | second item id |
| 6 | second item count |

#### 0xB5 `removeMiscItem`

| Byte | Meaning |
|---|---|
| 1-2 | item id |

#### 0xB6 `setFlagToActorDistance`

| Byte | Meaning |
|---|---|
| 1-2 | first actor |
| 3-4 | second actor |
| 5-6 | state flag id |

#### 0xB7 `specialOp`

| Byte | Meaning |
|---|---|
| 1 | sub-opcode |
| 2 | argument, if the sub-opcode takes one |
| 3-5 | unused, the script resumes at [6] |

#### 0xB9–0xBA, 0xBF `framebufferEffectParams`

| Opcode | Meaning |
|---|---|
| 0xB9 | Sets the ordering table index the frame buffer effect is drawn at. [1-2] = ordering table index. |
| 0xBA | Sets whether the frame buffer effect reads the previous frame. [1] = 1 for the previous frame, 0 for the current one. |
| 0xBF | Turns the frame buffer effect on or off with a preset and resets its parameters. [1-2] = 0 to turn off, else the ordering table index of the effect. |

#### 0xBB `setScreenBlur`

Needs the screen effects overlay loaded by opcode BC.

| Byte | Meaning |
|---|---|
| 1-2 | depth in the ordering table, 0 = off |

#### 0xBD `nop`

Only the room scripts of MAP101 and MAP213 use it, with the byte 0x0C, right after setEnteredDoor.

</details>

### 0xC0–0xEF: Camera and framebuffer effects

| Opcode | Len | Handler | Skipping | Summary |
|---|---|---|---|---|
| 0xC0 | 7 | `controlCameraChannel` | = | Controls the look-at (opcodes 0xC0 to 0xCB) or eye (0xD0 to 0xDB) camera channel, as chosen by bit 4 |
| 0xC1 | 1 | `controlCameraChannel` | = | *as above* |
| 0xC2–0xC3 | 3 | `controlCameraChannel` | = | *as above* |
| 0xC4 | 4 | `controlCameraChannel` | = | *as above* |
| 0xC5 | 9 | `controlCameraChannel` | = | *as above* |
| 0xC7 | 10 | `controlCameraChannel` | = | *as above* |
| 0xC8 | 11 | `controlCameraChannel` | = | *as above* |
| 0xC9 | 2 | `controlCameraChannel` | = | *as above* |
| 0xCA | 10 | `controlCameraChannel` | = | *as above* |
| 0xCB | 3 | `controlCameraChannel` | = | *as above* |
| 0xD0 | 7 | `controlCameraChannel` | = | *as above* |
| 0xD1 | 1 | `controlCameraChannel` | = | *as above* |
| 0xD2–0xD3 | 3 | `controlCameraChannel` | = | *as above* |
| 0xD4 | 4 | `controlCameraChannel` | = | *as above* |
| 0xD5 | 9 | `controlCameraChannel` | = | *as above* |
| 0xD7 | 10 | `controlCameraChannel` | = | *as above* |
| 0xD8 | 11 | `controlCameraChannel` | = | *as above* |
| 0xD9 | 2 | `controlCameraChannel` | = | *as above* |
| 0xDA | 10 | `controlCameraChannel` | = | *as above* |
| 0xDB | 3 | `controlCameraChannel` | = | *as above* |
| 0xDE | 2 | `stopCamera` | = | Interrupts camera movement and drops the momentum carried over from the last move (see opcode DF) |
| 0xDF | 2 | `setCameraMomentum` | = | Chooses whether the camera carries its speed over from the end of a move into the next one: it keeps going past the target and curves into the next move instead of stopping first |
| 0xE0 | 2 | `waitCameraIdle` | `yield` | Waits until the camera channels in a mask have finished moving, see getCameraIdleFlags |
| 0xE1 | 2 | `setFramebufferEffect` | = | Turns the frame buffer effect on or off |
| 0xE2–0xE3 | 6 | `tweenAngle` | = | Tweens an angle: the camera roll for E2, the spin of the frame buffer effect for E3 |
| 0xE4 | 5 | `framebufferEffectParams` | = | Sets the parameters of the frame buffer effect and the lens distortion |
| 0xE5 | 6 | `framebufferEffectParams` | = | *as above* |
| 0xE6 | 5 | `framebufferEffectParams` | = | *as above* |
| 0xE7 | 2 | `framebufferEffectParams` | = | *as above* |
| 0xE8 | 3 | `attachCameraToActor` | = | Attaches the camera to an actor |
| 0xE9 | 3 | `returnToGameplayCamera` | = | Moves the camera back to the gameplay view of Ashley, optionally turning it to a new facing and zoom |
| 0xEA–0xEC | 4 | `setProjectionClipAndShake` | = | Sets the projection distance, clip distances and shake of the camera |
| 0xED | 5 | `framebufferEffectParams` | = | *as above* |
| 0xEE | 0 | `setProjectionClipAndShake` | = | *as above* |
| 0xEF | 6 | `setProjectionClipAndShake` | = | *as above* |

<details>
<summary>Operands and details</summary>

#### 0xC0–0xC5, 0xC7–0xCB, 0xD0–0xD5, 0xD7–0xDB `controlCameraChannel`

The low nibble is the sub-opcode. An easing is a value of enum Easing, a duration is in steps of 1/30 s, and an angle is in ONE per turn.

| Opcode | Meaning |
|---|---|
| 0xC0 / 0xD0 (`cameraSetDestination`) | Stores a destination for the channel. [1-6] = x, y and z of the destination, as 16-bit world coordinates. |
| 0xC1 / 0xD1 (`cameraCut`) | Cuts the channel to its destination at once. |
| 0xC2 / 0xD2 (`cameraLerpTo`) | Moves the channel to its destination in a straight line. [1] = easing, [2] = duration. |
| 0xC3 / 0xD3 (`cameraArcTo`) | Moves the channel to its destination in an arc around the other channel. [1] = easing, [2] = duration. |
| 0xC4 / 0xD4 (`cameraOrbitTo`) | Orbits the channel around the other channel to its destination. [1] = angle easing in the high nibble, turn direction in the low nibble (0 = shortest way, 1 = positive, 15 = negative). [2] = height easing in the high nibble, distance easing in the low nibble. [3] = duration. |
| 0xC5 / 0xD5 (`cameraOrbitBy`) | Orbits the channel around the other channel by an angle. The destination is not used. [1-2] = signed angle. [3-4] = final height, as a world y. [5] = distance scale in 1/64 units. [6] = angle easing in the low nibble, distance easing in the high nibble. [7] = height easing. [8] = duration. |
| 0xC7 / 0xD7 (`cameraSetDestinationToActorOffset`) | Stores a destination that is an offset from a point on an actor. [1-2] = actor selector. [3] = point on the actor, a bone id or an ActorPoint. [4-9] = x, y and z of the offset, as 16-bit world values. |
| 0xC8 / 0xD8 (`cameraFollowActor`) | Follows an offset from a point on an actor. [1-9] = as for cameraSetDestinationToActorOffset. [10] = duration. |
| 0xC9 / 0xD9 (`cameraLockOffset`) | Holds the channel at its current offset from the other channel. [1] = duration. |
| 0xCA / 0xDA (`cameraSetDestinationToActorLocalOffset`) | As cameraSetDestinationToActorOffset, with the offset turned by the actor's facing. |
| 0xCB / 0xDB (`cameraTerrainFollowTo`) | Moves the channel horizontally to its destination, at a fixed height above the ground. [2] = duration, [1] is not used. |

#### 0xDE `stopCamera`

| Byte | Meaning |
|---|---|
| 1 | unused |

#### 0xDF `setCameraMomentum`

| Byte | Meaning |
|---|---|
| 1 | bit 0 for the look-at, bit 1 for the eye |

#### 0xE0 `waitCameraIdle`

The look-at and eye moves are started by vs_battle_script_controlCameraChannel.

| Byte | Meaning |
|---|---|
| 1 | mask of the channels to wait for |

#### 0xE1 `setFramebufferEffect`

| Byte | Meaning |
|---|---|
| 1 | 1 for on, 0 for off |

#### 0xE2–0xE3 `tweenAngle`

| Byte | Meaning |
|---|---|
| 1-2 | target angle |
| 3 | low nibble the easing, high nibble the direction: 0 negative, 1 shortest, 2 positive |
| 4 | duration, 0 sets the angle immediately |
| 5 | unused |

#### 0xE4–0xE7, 0xED `framebufferEffectParams`

| Opcode | Meaning |
|---|---|
| 0xE4 | Tweens the scale of the frame buffer effect. [1-2] = x and y scale (<< 7), [3] = easing, [4] = tween duration, 0 = immediate. |
| 0xE5 | Tweens the tint of the frame buffer effect. [1-3] = red, green and blue, [4] = easing, [5] = tween duration, 0 = immediate. |
| 0xE6 | Tweens the offset of the frame buffer effect. [1-2] = signed x and y offset, [3] = easing, [4] = tween duration, 0 = immediate. |
| 0xE7 | Sets the blend mode of the frame buffer effect. [1] = blend mode. |
| 0xED | Tweens the lens distortion, waiting for a previous tween to finish. [1] = zoom (<< 6), [2] = distortion (signed), [3] = easing, [4] = tween duration, 0 = immediate. See setScreenLensDistortion. |

#### 0xE8 `attachCameraToActor`

| Byte | Meaning |
|---|---|
| 1-2 | actor id, 0x2000 = detach |

#### 0xE9 `returnToGameplayCamera`

To restore the view saved before the scene, see sweepCameraToSavedPlayerView (special opcode B7, sub-opcode 9).

| Byte | Meaning |
|---|---|
| 1 | facing of the camera in 45 degree steps, 0xFF = unchanged |
| 2 | zoom, 1 = normal, 2 = zoomed out, 0 = unchanged |

#### 0xEA–0xEC, 0xEE–0xEF `setProjectionClipAndShake`

Opcode EE also uses this handler, but does nothing and does not return a result.

| Opcode | Meaning |
|---|---|
| 0xEA | Tweens the projection distance. [1] = projection distance (<< 2), 0 = default, [2] = easing, [3] = tween duration, 0 = immediate. |
| 0xEB | Tweens the near clip distance. [1] = distance, 0 = default, [2] = easing, [3] = tween duration, 0 = immediate. |
| 0xEC | Tweens the far clip distance. [1] = distance (<< 7), 0 = default, [2] = easing, [3] = tween duration, 0 = immediate. |
| 0xEF | Starts a camera shake in one of the two slots, or stops all shakes. [1] = number of oscillations, [2] = amplitude in world units, 0 stops all shakes, [3] = bit 0 shakes the look-at, bit 1 shakes the eye, bits 2-3, 4-5 and 6-7 are the weights of the shake along x, y and z, minus 1. The shake is turned by the heading of the camera, so x is sideways and z along the view. [4] = envelope, 0 = constant, 1 = fades out, 2 = swells then fades, 3 = fades in, [5] = duration. |

</details>

### 0xF0–0xFF: Timing, script slots and scene end

| Opcode | Len | Handler | Skipping | Summary |
|---|---|---|---|---|
| 0xF0 | 2 | `waitFrames` | `yield` | Waits for a number of frames |
| 0xF1 | 2 | `setFrameRate` | = | Sets the frame rate, see setFrameRate |
| 0xF2 | 5 | `playMenuSelectSfx` | = | Plays the menu select sound effect |
| 0xF3 | 2 | `setScanlines` | = | Toggles the scanline effect, see drawScanlines |
| 0xF4 | 2 | `joinScript` | = | Joins the code forked into a script slot by opcode F5 |
| 0xF5 | 4 | `forkAndJump` | = | Starts the script immediately following this opcode in a separate script slot, and jumps the current script ahead |
| 0xF6 | 2 | `endScript` | = | Ends the current script |
| 0xF7 | 3 | `queueNextEvt` | = | Starts loading an EVT file to continue into once the running script ends |
| 0xFE–0xFF | 1 | `endScene` | = | Waits until every text box has closed, then ends the scene |

<details>
<summary>Operands and details</summary>

#### 0xF0 `waitFrames`

| Byte | Meaning |
|---|---|
| 1 | frames to wait, must not be 0 |

#### 0xF1 `setFrameRate`

| Byte | Meaning |
|---|---|
| 1 | 2 for full rate, 4 for half, else ignored |

#### 0xF2 `playMenuSelectSfx`

Unused.

| Byte | Meaning |
|---|---|
| 1-4 | unused |

#### 0xF3 `setScanlines`

| Byte | Meaning |
|---|---|
| 1 | 1 for on, 0 for off |

#### 0xF4 `joinScript`

| Byte | Meaning |
|---|---|
| 1 | slot in the low 2 bits, bit 7 set to stop the slot instead of waiting |

#### 0xF5 `forkAndJump`

| Byte | Meaning |
|---|---|
| 1 | slot to run the forked script in, 1 to 3 |
| 2-3 | Current script continues from this offset |

#### 0xF6 `endScript`

In practice only used by forked scripts.

| Byte | Meaning |
|---|---|
| 1 | slot identifier, unused |

#### 0xF7 `queueNextEvt`

| Byte | Meaning |
|---|---|
| 1-2 | EVT file number |

#### 0xFE–0xFF `endScene`

Restores the full frame rate. No discernable difference in usage between 0xFE and 0xFF.

</details>

### Undefined opcodes

These 41 opcodes are routed to `invalidOpcode` in both tables: 0x00 to 0x09, 0x0B, 0x4D to 0x4F, 0x7F, 0x8A to 0x8E, 0xA7, 0xAB to 0xB0, 0xC6, 0xCC to 0xCF, 0xD6, 0xDC to 0xDD, 0xF8 to 0xFD. The handler formats a debug message into a buffer that is never shown and returns `scriptNext`, so the interpreter just steps over the opcode by its entry in the length table. Several of these entries are 0, so a script that reached one would never advance past it.

`0x1C` and `0xB4` are the only opcodes that are defined normally but are invalid in the skip table.
