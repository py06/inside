#define VLD_BTN 2
#define VLD_INT 0

#define UP_BTN 10
#define DWN_BTN 9

/* timings */
#define DEBOUNCE_TIME 250 /* 250ms debouncing perdiod */
#define LONG_PRESS_TIME (4 * 1000) /* 4s to siwtch in setting mode */

/* display context */
#define DISPLAY_STANDARD 0 /* normal display mode */
#define DISPLAY_SETTINGS 1 /* in settings and config context */

extern int context;

int get_displayContext(void);
int get_validButton(void);
int keypad_status(void);
void init_keypad(void);
void deinit_keypad(void);
void manage_keypad (void);
