static char secondaryTitleEnabled;
static char itemCategoryIconsEnabled;
static char statusCommandState;

/**
 * Toggles the display of the secondary title, the category icons,
 * and the status command.
 */
static void toggleMenuUi(char state)
{
    secondaryTitleEnabled = state;
    itemCategoryIconsEnabled = state;
    statusCommandState = state;
}
