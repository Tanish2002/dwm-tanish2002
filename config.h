/* -*--*-*-*-*-*-*-*-*- GAPS -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */
#define GAPS_START 30
#define BORDERPX_START 0
/* -*-*-*-*-*-*-*-*-*- NO GAPS *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */
/* #define GAPS_START 0 */
/* #define BORDERPX_START 1 */
/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */

/* -*-*-*-*-*-*-*-*- FLOATING BAR -*-*-*-*-*-*-*-*-*-*-*-*-*-* */
/*static const unsigned int gappih    = 10;     */  /* horiz inner gap between windows */
/*static const unsigned int gappiv    = 10;     */  /* vert inner gap between windows */
/*static const unsigned int gappoh    = 10;     */  /* horiz outer gap between windows and screen edge */
/*static const unsigned int gappov    = 10;     */  /* vert outer gap between windows and screen edge */
static const int vertpad     = GAPS_START - GAPS_START / 3; // vertical padding of bar
static const int sidepad     = GAPS_START - GAPS_START / 3; // horizontal padding of bar
static const int horizpadbar = 6;          // horizontal padding for statusbar
static const int vertpadbar  = 12;         // vertical padding for statusbar
/* -*-*-*-*-*-*-*-* NON-FLOATING BAR -*-*-*-*-*-*-*-*-*-*-*-*- */
/* static const int vertpad     = 0; // vertical padding of bar */
/* static const int sidepad     = 0; // horizontal padding of bar */
/* static const int horizpadbar = 2; // horizontal padding for statusbar */
/* static const int vertpadbar  = 4; // vertical padding for statusbar */
/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

// for use with the rounded corners patch (0 disables)
static const int CORNER_RADIUS = 0;

static const char*fonts[] = {
    "ShureTechMono Nerd Font:size=10",
    "RobotoMono Nerd Font Mono:size=10"
    /* "Terminus:size=8", */
};

static const Rule rules[] = {
    /* class          instance    title    tags mask  iscentered   isfloating   monitor */
    { "st-256color",  NULL,      0,             0,         1,           0,           -1 },
    { 0,              NULL,      "draw",      0,         0,           1,           -1 },
    { 0,              NULL,      "floating-st", 0,         1,           1,           -1 },
    { "feh",          NULL,      0,             0,         1,           1,           -1 },
    { "mpv",          NULL,      0,             0,         1,           1,           -1 },
    { "mupdf",        NULL,      0,             0,         1,           0,           -1 },
    { "MuPDF",        NULL,      0,             0,         1,           0,           -1 },

};


static const char norm_fg[] = "#d4ddda"; 
static const char norm_bg[] = "#062C39"; 
static const char norm_border[] = "#949a98";
static const char sel_fg[] = "#d4ddda"; 
static const char sel_bg[] = "#494262"; 
static const char sel_border[] = "#d4ddda"; 
static const char urg_fg[] = "#d4ddda"; 
static const char urg_bg[] = "#45405F"; 
static const char urg_border[] = "#45405F"; 
static const char *colors[][3]      = { 
/*               fg           bg         border                         */ 
[SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins 
[SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
[SchemeUrg] =  { urg_fg,      urg_bg,    urg_border }, 
}; 

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */
/*
 * cool emojis to use for tags:
 *
 * "", "爵", "", "", "ﭮ", "", "", "", "","", "﬐", "ﳨ"
 * "ﯙ", "", "", "", "", "", "", "", "", "", "", ""
 * "", "", "", "", "", "", "", "", "", "", "", ""
 */
static const char *tags[] = { "", "", "", "", "", "ﭮ" };
/* static const char *tags[] = { "1","2","3","4","5","6" }; */
/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */

static const int showbar = 1;
static const int topbar  = 1;
static const float mfact = 0.5;
static const Layout layouts[] = {
    { "|  ", tile },
    { "| 缾 ", NULL }, // floating
    { "|  ", monocle },
};
#define TAGKEYS(KEY,TAG) { Mod4Mask, KEY, view, {.ui = 1 << TAG} }, \
                         { Mod4Mask|ShiftMask, KEY, tag, {.ui = 1 << TAG} },
#define SH(cmd) { .v = (const char*[]) { "/bin/zsh", "-c", cmd, NULL } }
static const char *term[] = { "st", NULL };
#include <X11/XF86keysym.h>
static Key keys[] = {
    /* modifier            key        function       argument */
    /* -*-*-*-*-*-*-*- programs -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */
    { Mod4Mask,             XK_Return, spawn,        SH("tabbed -d -c -r 2 st -w ''") },
    { Mod4Mask|ShiftMask,   XK_Return, spawn,        { .v = term, }         },
    { Mod4Mask,             XK_grave,  spawn,        SH("$HOME/bin/term_draw")         },
    { Mod4Mask,             XK_d,      spawn,        SH("rofi -show drun") },
    { Mod4Mask,             XK_n,      spawn,        SH("$HOME/bin/Theme-change") },
    { Mod4Mask,             XK_c,      spawn,        SH("$HOME/bin/rofi-clip")             },
    { 0,                    XK_Print,  spawn,        SH("$HOME/bin/screenshot-menu.sh")            },
    /* { Mod1Mask|ShiftMask,   XK_w,      spawn,        SH("tabbed -d -c surf -e") }, */
    { Mod4Mask,             XK_Delete, spawn,        SH("$HOME/bin/rofi-emoji")              },
    { Mod1Mask|ControlMask, XK_k,      spawn,        SH("keylayout")        },
    /* -*-*-*-*-*-*-*- media control -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */
    { Mod4Mask,      XK_m,                        spawn,  SH("$HOME/bin/rofi_mpvtube") },  
    { 0,             XF86XK_AudioRaiseVolume,     spawn,  SH("amixer sset Master 5%+") },
    { 0,             XF86XK_AudioLowerVolume,     spawn,  SH("amixer sset Master 5%-") },
    { 0,             XF86XK_AudioMute,            spawn,  SH("amixer sset Master toggle") },
    { 0,             XF86XK_AudioPlay,            spawn,  SH("$HOME/bin/mpvctl -t")   },
    { 0,             XF86XK_AudioNext,            spawn,  SH("$HOME/bin/mpvctl -n")   },
    { 0,             XF86XK_AudioPrev,            spawn,  SH("$HOME/bin/mpvctl -p")   },
    /* -*-*-*-*-*-*-*- dwm commands -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */
    { Mod1Mask,            XK_space,  togglescratch, SH("st -t scratchpad -g 68x18") },
    { Mod4Mask|ShiftMask,  XK_q,      killclient,    {0} },
    { Mod4Mask,            XK_Tab,    focusstack,    {.i = +1 } },
    { Mod4Mask|ShiftMask,  XK_Left,   setmfact,      {.f = -0.05} },
    { Mod4Mask|ShiftMask,  XK_Right,  setmfact,      {.f = +0.05} },
    { Mod4Mask,            XK_t,      setlayout,     {.v = &layouts[0]} },
    { Mod4Mask,            XK_s,      setlayout,     {.v = &layouts[1]} },
    { Mod4Mask|ShiftMask,  XK_m,      setlayout,     {.v = &layouts[2]} },
    { Mod4Mask,            XK_b,      togglebar,     {0} },
    { Mod4Mask|ShiftMask,  XK_s,      togglesticky,  {0} },
    { Mod4Mask|ShiftMask,  XK_space,  togglefloating,{0} },
    { Mod4Mask,            XK_h,      rotatestack,   {.i = -1 } },
    { Mod4Mask,            XK_l,      rotatestack,   {.i = +1 } },
    { Mod4Mask,            XK_Tab,    view,          {0} },
    { Mod4Mask|ShiftMask,  XK_Escape, quit,          {0} },
    { Mod4Mask|ShiftMask,  XK_r,      quit,          {1} },
    /* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */
    { Mod4Mask|ShiftMask,  XK_Up,     setsmfact,      {.f = +0.05} },
    { Mod4Mask|ShiftMask,  XK_Down,   setsmfact,      {.f = -0.05} },
    { Mod4Mask,            XK_g,      setgaps,        {.i = +4}    },
    { Mod4Mask|ShiftMask,  XK_g,      setgaps,        {.i = -4}    },
    { Mod4Mask,            XK_f,      togglefullscr,  {0} },
    /* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */
    TAGKEYS(XK_1,0) TAGKEYS(XK_2,1) TAGKEYS(XK_3,2) TAGKEYS(XK_4,3) 
    TAGKEYS(XK_5,4) TAGKEYS(XK_6,5) 
    // -- if 4 WS:
    /* TAGKEYS(XK_BackSpace,3) */
    // -- if 6 WS:
    TAGKEYS(XK_BackSpace,5)
};

static Button buttons[] = {
    { ClkClientWin,         Mod4Mask,       Button1,        movemouse,      {0} },
    { ClkClientWin,         Mod4Mask,       Button3,        resizemouse,    {0} },
    { ClkRootWin,           0,              Button3,        spawn,          SH("x9term") },
};

static unsigned int gappx = GAPS_START;
static unsigned int borderpx = BORDERPX_START;

static const unsigned int minwsz = 20; /* min height of a client for smfact */

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */
static const float smfact     = 0.00; /* factor of tiled clients [0.00..0.95] */
static const int resizehints  = 1;
static const int focusonwheel = 0;
static const char scratchpadname[] = "scratchpad";
static const int nmaster      = 1;
