#ifndef COMMON_H
#define COMMON_H

#define SHADOW_WIDTH            5
#define WINDOW_WIDTH            680
#define WINDOW_HEIGHT           372
#define WINDOW_START_X          0
#define WINDOW_START_Y          0
#define WINDOW_PAGE_COUNT       4
#define WINDOW_BUTTON_COUNT     4
#define WINDOW_PAGE_MOVE        20
#define WINDOW_ONEBUTTON_WIDTH  170
#define DEFAULT_SKIN            ":/skin/17_big"

typedef enum{
    UI_EN,
    UI_ZH
}LANGUAGE;

typedef enum{
    SAFE,
    SINA,
    RENREN
}LOGIN;

typedef enum{
    HELP_ONLINE,
    PLATFORM_HELP,
    LOGIN_HOME,
    PROTECT
}ACTION;

typedef enum{
    NORMAL,
    ENTER,
    PRESS,
    NOSTATUS
}ButtonStatus;

#endif // COMMON_H
