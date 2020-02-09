#include <string>

const std::string INPUT_DEVICE_DIR = "/dev/input/";
const std::string EVENT_DEVICE_NAME = "event";

const char* keys[] = {
    "<reserved>",                      // #define KEY_RESERVED		0
    "<esc>",                           // #define KEY_ESC			1
    "1",                               // #define KEY_1			2
    "2",                               // #define KEY_2			3
    "3",                               // #define KEY_3			4
    "4",                               // #define KEY_4			5
    "5",                               // #define KEY_5			6
    "6",                               // #define KEY_6			7
    "7",                               // #define KEY_7			8
    "8",                               // #define KEY_8			9
    "9",                               // #define KEY_9			10
    "0",                               // #define KEY_0			11
    "-",                               // #define KEY_MINUS		12
    "=",                               // #define KEY_EQUAL		13
    "<bs>",                            // #define KEY_BACKSPACE		14
    "<tab>",                           // #define KEY_TAB			15
    "Q",                               // #define KEY_Q			16
    "W",                               // #define KEY_W			17
    "E",                               // #define KEY_E			18
    "R",                               // #define KEY_R			19
    "T",                               // #define KEY_T			20
    "Y",                               // #define KEY_Y			21
    "U",                               // #define KEY_U			22
    "I",                               // #define KEY_I			23
    "O",                               // #define KEY_O			24
    "P",                               // #define KEY_P			25
    "{",                               // #define KEY_LEFTBRACE		26
    "}",                               // #define KEY_RIGHTBRACE		27
    "<enter>",                         // #define KEY_ENTER		28
    "<l-ctrl>",                        // #define KEY_LEFTCTRL		29
    "A",                               // #define KEY_A			30
    "S",                               // #define KEY_S			31
    "D",                               // #define KEY_D			32
    "F",                               // #define KEY_F			33
    "G",                               // #define KEY_G			34
    "H",                               // #define KEY_H			35
    "J",                               // #define KEY_J			36
    "K",                               // #define KEY_K			37
    "L",                               // #define KEY_L			38
    ";",                               // #define KEY_SEMICOLON		39
    "'",                               // #define KEY_APOSTROPHE		40
    "`",                               // #define KEY_GRAVE		41
    "<l-shift>",                       // #define KEY_LEFTSHIFT		42
    "\\",                              // #define KEY_BACKSLASH		43
    "Z",                               // #define KEY_Z			44
    "X",                               // #define KEY_X			45
    "C",                               // #define KEY_C			46
    "V",                               // #define KEY_V			47
    "B",                               // #define KEY_B			48
    "N",                               // #define KEY_N			49
    "M",                               // #define KEY_M			50
    ",",                               // #define KEY_COMMA		51
    ".",                               // #define KEY_DOT			52
    "/",                               // #define KEY_SLASH		53
    "<r-shift>",                       // #define KEY_RIGHTSHIFT		54
    "*",                               // #define KEY_KPASTERISK		55
    "<l-alt>",                         // #define KEY_LEFTALT		56
    "<space>",                         // #define KEY_SPACE		57
    "<capslock>",                      // #define KEY_CAPSLOCK		58
    "F1",                              // #define KEY_F1			59
    "F2",                              // #define KEY_F2			60
    "F3",                              // #define KEY_F3			61
    "F4",                              // #define KEY_F4			62
    "F5",                              // #define KEY_F5			63
    "F6",                              // #define KEY_F6			64
    "F7",                              // #define KEY_F7			65
    "F8",                              // #define KEY_F8			66
    "F9",                              // #define KEY_F9			67
    "F10",                             // #define KEY_F10			68
    "<numlock>",                       // #define KEY_NUMLOCK		69
    "<scrolllock>",                    // #define KEY_SCROLLLOCK		70
    "KP7",                             // #define KEY_KP7			71
    "KP8",                             // #define KEY_KP8			72
    "KP9",                             // #define KEY_KP9			73
    "KPMinus",                         // #define KEY_KPMINUS		74
    "KP4",                             // #define KEY_KP4			75
    "KP5",                             // #define KEY_KP5			76
    "KP6",                             // #define KEY_KP6			77
    "KPPlus",                          // #define KEY_KPPLUS		78
    "KP1",                             // #define KEY_KP1			79
    "KP2",                             // #define KEY_KP2			80
    "KP3",                             // #define KEY_KP3			81
    "KP0",                             // #define KEY_KP0			82
    "KPDot",                           // #define KEY_KPDOT		    83
    "EMPTY-84",                        //  Here can be error in creating list buttons =) Padding will be further if to be mistaken
    "Zenkaku/Hankaku",                 // #define KEY_ZENKAKUHANKAKU	85
    "102nd",                           // #define KEY_102ND		    86
    "F11",                             // #define KEY_F11			87
    "F12",                             // #define KEY_F12			88
    "RO",                              // #define KEY_RO			89
    "Katakana",                        // #define KEY_KATAKANA		90
    "HIRA",                            // #define KEY_HIRAGANA		91
    "Henkan",                          // #define KEY_HENKAN		92
    "Kata",                            // #define KEY_KATAKANAHIRAGANA	93
    "Muhenkan",                        // #define KEY_MUHENKAN		94
    "KPJp",                            // #define KEY_KPJPCOMMA		95
    "KPEnter",                         // #define KEY_KPENTER		96
    "<r-ctrl>",                            // #define KEY_RIGHTCTRL		97
    "KPSlash",                         // #define KEY_KPSLASH		98
    "SysR",                            // #define KEY_SYSRQ		    99
    "<r-alt>",                         // #define KEY_RIGHTALT		100
    "Line",                            // #define KEY_LINEFEED		101
    "Home",                            // #define KEY_HOME		    102
    "<up>",                            // #define KEY_UP			103
    "PageUp",                          // #define KEY_PAGEUP		104
    "<left>",                          // #define KEY_LEFT		    105
    "<right>",                         // #define KEY_RIGHT		    106
    "End",                             // #define KEY_END			107
    "<down>",                          // #define KEY_DOWN		    108
    "PageDown",                        // #define KEY_PAGEDOWN		109
    "<insert>",                        // #define KEY_INSERT		110
    "<delete>",                        // #define KEY_DELETE		111
    "Macro",                           // #define KEY_MACRO		    112
    "Mute",                            // #define KEY_MUTE		    113
    "<volume-down>",                   // #define KEY_VOLUMEDOWN	114
    "<volume-up>",                     // #define KEY_VOLUMEUP		115
    "<power>",                         // #define KEY_POWER		    116	/* SC System Power Down */
    "KPEqual",                         // #define KEY_KPEQUAL		117
    "KPPlusMinus",                     // #define KEY_KPPLUSMINUS	118
    "Pause",                           // #define KEY_PAUSE		    119
    "KPComma",                         // #define KEY_SCALE		    120	/* AL Compiz Scale (Expose) */
    "Hanguel",                         //
    "Hanja",                           // #define KEY_KPCOMMA		121
    "Yen",                             // #define KEY_HANGEUL		122
    "LeftMeta",                        // #define KEY_HANGUEL		KEY_HANGEUL
    "RightMeta",                       // #define KEY_HANJA		    123
    "<super>",                         // #define KEY_YEN			124
    "Stop",                            // #define KEY_LEFTMETA		125
    "Again",                           // #define KEY_RIGHTMETA		126
    "Props",                           // #define KEY_COMPOSE		127
    "Undo",                            //
    "Front",                           // #define KEY_STOP		    128	/* AC Stop */
    "Copy",                            // #define KEY_AGAIN		    129
    "Open",                            // #define KEY_PROPS		    130	/* AC Properties */
    "Paste",                           // #define KEY_UNDO		    131	/* AC Undo */
    "Find",                            // #define KEY_FRONT		    132
    "Cut",                             // #define KEY_COPY		    133	/* AC Copy */
    "Help",                            // #define KEY_OPEN		    134	/* AC Open */
    "Menu",                            // #define KEY_PASTE		    135	/* AC Paste */
    "Calc",                            // #define KEY_FIND		    136	/* AC Search */
    "Setup",                           // #define KEY_CUT			137	/* AC Cut */
    "Sleep",                           // #define KEY_HELP		    138	/* AL Integrated Help Center */
    "WakeUp",                          // #define KEY_MENU		    139	/* Menu (show menu) */
    "File",                            // #define KEY_CALC		    140	/* AL Calculator */
    "SendFile",                        // #define KEY_SETUP		    141
    "DeleteFile",                      // #define KEY_SLEEP		    142	/* SC System Sleep */
    "X-fer",                           // #define KEY_WAKEUP		143	/* System Wake Up */
    "Prog1",                           // #define KEY_FILE		    144	/* AL Local Machine Browser */
    "Prog2",                           // #define KEY_SENDFILE		145
    "WWW",                             // #define KEY_DELETEFILE	146
    "MSDOS",                           // #define KEY_XFER		    147
    "Coffee",                          // #define KEY_PROG1		    148
    "Direction",                       // #define KEY_PROG2		    149
    "CycleWindows",                    // #define KEY_WWW			150	/* AL Internet Browser */
    "Mail",                            // #define KEY_MSDOS		    151
    "Bookmarks",                       // #define KEY_COFFEE		152	/* AL Terminal Lock/Screensaver */
    "Computer",                        // #define KEY_SCREENLOCK		KEY_COFFEE
    "Back",                            // #define KEY_ROTATE_DISPLAY	153	/* Display orientation for e.g. tablets */
    "Forward",                         // #define KEY_DIRECTION		KEY_ROTATE_DISPLAY
    "CloseCD",                         // #define KEY_CYCLEWINDOWS	154
    "EjectCD",                         // #define KEY_MAIL		    155
    "EjectCloseCD",                    // #define KEY_BOOKMARKS		156	/* AC Bookmarks */
    "NextSong",                        // #define KEY_COMPUTER		157
    "PlayPause",                       // #define KEY_BACK		    158	/* AC Back */
    "PreviousSong",                    // #define KEY_FORWARD		159	/* AC Forward */
    "StopCD",                          // #define KEY_CLOSECD		160
    "Record",                          // #define KEY_EJECTCD		161
    "Rewind",                          // #define KEY_EJECTCLOSECD	162
    "Phone",                           // #define KEY_NEXTSONG		163
    "ISOKey",                          // #define KEY_PLAYPAUSE		164
    "Config",                          // #define KEY_PREVIOUSSONG	165
    "HomePage",                        // #define KEY_STOPCD		166
    "Refresh",                         // #define KEY_RECORD		167
    "Exit",                            // #define KEY_REWIND		168
    "Move",                            // #define KEY_PHONE		    169	/* Media Select Telephone */
    "Edit",                            // #define KEY_ISO			170
    "ScrollUp",                        // #define KEY_CONFIG		171	/* AL Consumer Control Configuration */
    "ScrollDown",                      // #define KEY_HOMEPAGE		172	/* AC Home */
    "KPLeftParenthesis",               // #define KEY_REFRESH		173	/* AC Refresh */
    "KPRightParenthesis",              // #define KEY_EXIT		    174	/* AC Exit */
    "F13",                             // #define KEY_MOVE		    175
    "F14",                             // #define KEY_EDIT		    176
    "F15",                             // #define KEY_SCROLLUP		177
    "F16",                             // #define KEY_SCROLLDOWN	178
    "F17",                             // #define KEY_KPLEFTPAREN	179
    "F18",                             // #define KEY_KPRIGHTPAREN	180
    "F19",                             // #define KEY_NEW			181	/* AC New */
    "F20",                             // #define KEY_REDO		    182	/* AC Redo/Repeat */
    "F21",                             //
    "F22",                             // #define KEY_F13			183
    "F23",                             // #define KEY_F14			184
    "F24",                             // #define KEY_F15			185
    "PlayCD",                          // #define KEY_F16			186
    "PauseCD",                         // #define KEY_F17			187
    "Prog3",                           // #define KEY_F18			188
    "Prog4",                           // #define KEY_F19			189
    "Suspend",                         // #define KEY_F20			190
    "Close",                           // #define KEY_F21			191
    "Play",                            // #define KEY_F22			192
    "Fast Forward",                    // #define KEY_F23			193
    "Bass Boost",                      // #define KEY_F24			194
    "Print",                           //
    "HP",                              // #define KEY_PLAYCD		200
    "Camera",                          // #define KEY_PAUSECD		201
    "Sound",                           // #define KEY_PROG3		    202
    "Question",                        // #define KEY_PROG4		    203
    "Email",                           // #define KEY_DASHBOARD		204	/* AL Dashboard */
    "Chat",                            // #define KEY_SUSPEND		205
    "Search",                          // #define KEY_CLOSE		    206	/* AC Close */
    "Connect",                         // #define KEY_PLAY		    207
    "Finance",                         // #define KEY_FASTFORWARD	208
    "Sport",                           // #define KEY_BASSBOOST		209
    "Shop",                            // #define KEY_PRINT		    210	/* AC Print */
    "Alternate Erase",                 // #define KEY_HP			211
    "Cancel",                          // #define KEY_CAMERA		212
    "Brightness down",                 // #define KEY_SOUND		    213
    "Brightness up",                   // #define KEY_QUESTION		214
    "Media",                           // #define KEY_EMAIL		    215
    "Unknown",                         // #define KEY_CHAT		    216
    "Btn0",                            // #define KEY_SEARCH		217
    "Btn1",                            // #define KEY_CONNECT		218
    "Btn2",                            // #define KEY_FINANCE		219	/* AL Checkbook/Finance */
    "Btn3",                            // #define KEY_SPORT		    220
    "Btn4",                            // #define KEY_SHOP		    221
    "Btn5",                            // #define KEY_ALTERASE		222
    "Btn6",                            // #define KEY_CANCEL		223	/* AC Cancel */
    "Btn7",                            // #define KEY_BRIGHTNESSDOWN	224
    "Btn8",                            // #define KEY_BRIGHTNESSUP	225
    "Btn9",                            // #define KEY_MEDIA		    226
    "LeftBtn",                         //
    "RightBtn",                        // #define KEY_SWITCHVIDEOMODE	227	/* Cycle between available video
    "MiddleBtn",                       // 					   outputs (Monitor/LCD/TV-out/etc) */
    "SideBtn",                         // #define KEY_KBDILLUMTOGGLE	228
    "ExtraBtn",                        // #define KEY_KBDILLUMDOWN  	229
    "ForwardBtn",                      // #define KEY_KBDILLUMUP		230
    "BackBtn",                         //
    "TaskBtn",                         // #define KEY_SEND		        231	/* AC Send */
    "Trigger",                         // #define KEY_REPLY		        232	/* AC Reply */
    "ThumbBtn",                        // #define KEY_FORWARDMAIL		233	/* AC Forward Msg */
    "ThumbBtn2",                       // #define KEY_SAVE		        234	/* AC Save */
    "TopBtn",                          // #define KEY_DOCUMENTS		    235
    "TopBtn2",                         //
    "PinkieBtn",                       // #define KEY_BATTERY		    236
    "BaseBtn",                         //
    "BaseBtn2",                        // #define KEY_BLUETOOTH		    237
    "BaseBtn3",                        // #define KEY_WLAN		        238
    "BaseBtn4",                        // #define KEY_UWB			    239
    "BaseBtn5",                        //
    "BaseBtn6",                        // #define KEY_UNKNOWN		    240
    "BtnDead",                         //
    "BtnA",                            // #define KEY_VIDEO_NEXT		241	/* drive next video source */
    "BtnB",                            // #define KEY_VIDEO_PREV		242	/* drive previous video source */
    "BtnC",                            // #define KEY_BRIGHTNESS_CYCLE	243	/* brightness up, after max is min */
    "BtnX",                            // #define KEY_BRIGHTNESS_AUTO	244	/* Set Auto Brightness: manual
    "BtnY",                            // 					  brightness control is off,
    "BtnZ",                            // 					  rely on ambient */
    "BtnTL",                           // #define KEY_BRIGHTNESS_ZERO	KEY_BRIGHTNESS_AUTO
    "BtnTR",                           // #define KEY_DISPLAY_OFF		245	/* display device to off state */
    "BtnTL2",                          //
    "BtnTR2",                          // #define KEY_WWAN		        246	/* Wireless WAN (LTE, UMTS, GSM, etc.) */
    "BtnSelect",                       // #define KEY_WIMAX		KEY_WWAN
    "BtnStart",                        // #define KEY_RFKILL		    247	/* Key that controls all radios */
    "BtnMode",                         //
    "BtnThumbL",                       // #define KEY_MICMUTE		    248	/* Mute / unmute the microphone */
    "BtnThumbR",
    "ToolPen",
    "ToolRubber",
    "ToolBrush",
    "ToolPencil",
    "ToolAirbrush",
    "ToolFinger",
    "ToolMouse",
    "ToolLens",
    "Touch",
    "Stylus",
    "Stylus2",
    "Tool Doubletap",
    "Tool Tripletap",
    "WheelBtn",
    "Gear up",
    "Ok",
    "Select",
    "Goto",
    "Clear",
    "Power2",
    "Option",
    "Info",
    "Time",
    "Vendor",
    "Archive",
    "Program",
    "Channel",
    "Favorites",
    "EPG",
    "PVR",
    "MHP",
    "Language",
    "Title",
    "Subtitle",
    "Angle",
    "Zoom",
    "Mode",
    "Keyboard",
    "Screen",
    "PC",
    "TV",
    "TV2",
    "VCR",
    "VCR2",
    "Sat",
    "Sat2",
    "CD",
    "Tape",
    "Radio",
    "Tuner",
    "Player",
    "Text",
    "DVD",
    "Aux",
    "MP3",
    "Audio",
    "Video",
    "Directory",
    "List",
    "Memo",
    "Calendar",
    "Red",
    "Green",
    "Yellow",
    "Blue",
    "ChannelUp",
    "ChannelDown",
    "First",
    "Last",
    "AB",
    "Next",
    "Restart",
    "Slow",
    "Shuffle",
    "Break",
    "Previous",
    "Digits",
    "TEEN",
    "TWEN",
    "Delete EOL",
    "Delete EOS",
    "Insert line",
    "Delete line",
};

