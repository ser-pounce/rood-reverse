static char _secondaryTitleEnabled;
static char _itemCategoryIconsEnabled;
static char _statusCommandState;

/**
 * Toggles the display of the secondary title, the category icons,
 * and the status command.
 */
static void _toggleMenuUi(char state)
{
    _secondaryTitleEnabled = state;
    _itemCategoryIconsEnabled = state;
    _statusCommandState = state;
}
