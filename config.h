/* -*--*-*-*-*-*-*-*-*- GAPS -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */
#define GAPS_START 22
#define BORDERPX_START 2
/* -*-*-*-*-*-*-*-*-*- SMALL GAPS *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */
/* #define GAPS_START 8 */
/* #define BORDERPX_START 1 */
/* -*-*-*-*-*-*-*-*-*- NO GAPS *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */
/* #define GAPS_START 0 */
/* #define BORDERPX_START 1 */
/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */

/* -*-*-*-*-*-*-*-*- FLOATING BAR -*-*-*-*-*-*-*-*-*-*-*-*-*-* */
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
    { "tabbed",       NULL,      0,             0,         1,           0,           -1 },
    { 0,              NULL,      "x9term",      0,         0,           1,           -1 },
    { 0,              NULL,      "floating-st", 0,         1,           1,           -1 },
    { "feh",          NULL,      0,             0,         1,           1,           -1 },
    { "mpv",          NULL,      0,             0,         1,           1,           -1 },
    { "mupdf",        NULL,      0,             0,         1,           0,           -1 },
    { "MuPDF",        NULL,      0,             0,         1,           0,           -1 },
    { "discord",      NULL,      0,        1 << 5,         1,           0,           -1 },
    { "Firefox",      NULL,      0,        1 << 0,         1,           0,           -1 },
};


/* Norm Colors */
static char normbgcolor[]           = "#222222";
static char normfgcolor[]           = "#bbbbbb";
static char normbordercolor[]       = "#444444";

/* Sel Colors */
static char selbgcolor[]            = "#005577";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";

static char *colors[][3] = {
/*               fg           bg           border   */
[SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
[SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
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
#include "fibonacci.c"
static const Layout layouts[] = {
    { "|  " , tile },
    { "| 缾 ", NULL }, // floating
    { "|  ", monocle },
    { "(@)",   spiral },
    { "[\\]",  dwindle },
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) { MODKEY, KEY, view, {.ui = 1 << TAG} }, \
                         { MODKEY|ShiftMask, KEY, tag, {.ui = 1 << TAG} },
#define SH(cmd) { .v = (const char*[]) { "/bin/sh", "-c", cmd, NULL } }
static const char *term[] = { "st", NULL };
#include <X11/XF86keysym.h>
static Key keys[] = {
    /* modifier            key                       function       argument */
    /* -*-*-*-*-*-*-*- programs -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */
    { MODKEY,             XK_Return,                 spawn,         SH("tabbed -d -c -r 2 st -w ''") },
    { MODKEY|ShiftMask,   XK_Return,                 spawn,         { .v = term, }         },
    { MODKEY,             XK_grave,                  spawn,         SH("$HOME/bin/term-draw")         },
    { MODKEY,             XK_d,                      spawn,         SH("rofi -show drun") },
    { MODKEY,             XK_n,                      spawn,         SH("$HOME/bin/Theme-change") },
    { MODKEY,             XK_c,                      spawn,         SH("$HOME/bin/rofi-clip") },
    { MODKEY,             XK_m,                      spawn,         SH("$HOME/bin/rofi_mpvtube") },
    { 0,                  XK_Print,                  spawn,         SH("$HOME/bin/screenshot-menu.sh")             },
    /* -*-*-*-*-*-*-*- media control -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */
    { 0,                  XF86XK_AudioRaiseVolume,   spawn,         SH("amixer sset Master 5%+") },
    { 0,                  XF86XK_AudioLowerVolume,   spawn,         SH("amixer sset Master 5%-") },
    { 0,                  XF86XK_AudioMute,          spawn,         SH("amixer sset Master toggle")   },
    { 0,                  XF86XK_AudioPlay,          spawn,         SH("$HOME/bin/mpvctl -t")   },
    { 0,                  XF86XK_AudioNext,          spawn,         SH("pkill skroll ; $HOME/bin/mpvctl -n")   },
    { 0,                  XF86XK_AudioPrev,          spawn,         SH("pkill skroll ; $HOME/bin/mpvctl -p")   },
    { 0,                  XF86XK_MonBrightnessUp,    spawn,         SH("xbacklight -inc 10")   },
    { 0,                  XF86XK_MonBrightnessDown,  spawn,         SH("xbacklight -dec 10")   },
    /* -*-*-*-*-*-*-*- dwm commands -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */
    { MODKEY,            XK_space,                   togglescratch, SH("st -t scratchpad -g 68x18") },
    { MODKEY|ShiftMask,  XK_q,                       killclient,    {0} },
    { MODKEY,            XK_Tab,                     focusstack,    {.i = +1 } },
    /*    { MODKEY,            XK_k,                       focusstack,    {.i = -1 } }, */
    { MODKEY|ShiftMask,  XK_Left,                    setmfact,      {.f = -0.05} },
    { MODKEY|ShiftMask,  XK_Right,                   setmfact,      {.f = +0.05} },
    { MODKEY|ShiftMask,  XK_t,                       setlayout,     {.v = &layouts[0]} },
    { MODKEY|ShiftMask,  XK_s,                       setlayout,     {.v = &layouts[1]} },
    { MODKEY,            XK_m,                       setlayout,     {.v = &layouts[2]} },
    { MODKEY|ShiftMask,  XK_f,                       setlayout,     {.v = &layouts[4]} },
    { MODKEY,            XK_b,                       togglebar,     {0} },
    { MODKEY|ShiftMask,  XK_space,                   togglesticky,  {0} },
    { MODKEY,            XK_s,                       togglefloating,{0} },
    { MODKEY,            XK_t,                       togglefloating,{0} },
    { MODKEY,            XK_Left,                    rotatestack,   {.i = -1 } },
    { MODKEY,            XK_Right,                   rotatestack,   {.i = +1 } },
    /*    { MODKEY,            XK_Tab,                     view,          {0} }, */
    { MODKEY,            XK_F5,                      xrdb,          {.v = NULL } },
    { MODKEY|ShiftMask,  XK_Escape,                  quit,          {0} },
    { MODKEY|ShiftMask,  XK_r,                       quit,          {1} },
    /* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */
 /*   { MODKEY|ShiftMask,  XK_k,                      setsmfact,      {.f = +0.05} }, */
 /*   { MODKEY|ShiftMask,  XK_j,                      setsmfact,      {.f = -0.05} }, */
    { MODKEY,            XK_g,                      setgaps,        {.i = +4}    },
    { MODKEY|ShiftMask,  XK_g,                      setgaps,        {.i = -4}    },
    { MODKEY,            XK_f,                      togglefullscr,  {0} },
    /* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */
    TAGKEYS(XK_1,0) TAGKEYS(XK_2,1) TAGKEYS(XK_3,2) TAGKEYS(XK_4,3) 
    TAGKEYS(XK_5,4) TAGKEYS(XK_6,5) 
    // -- if 4 WS:
    /* TAGKEYS(XK_BackSpace,3) */
    // -- if 6 WS:
    TAGKEYS(XK_BackSpace,5)
};

static Button buttons[] = {
    { ClkClientWin,  MODKEY,  Button1, movemouse,   {0} },
    { ClkClientWin,  MODKEY,  Button3, resizemouse, {0} },
    { ClkRootWin,    0,       Button3, spawn,       SH("x9term") }, // p9 rio style terminal drawing
	{ ClkTagBar,     0,       Button1,        view,           {0} },
};

static unsigned int gappx = GAPS_START;
static unsigned int borderpx = BORDERPX_START;

static const unsigned int minwsz = 20; /* min height of a client for smfact */

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */
static const float smfact     = 0.00; /* factor of tiled clients [0.00..0.95] */
static const int resizehints  = 1;
static const int focusonwheel = 1;
static const char scratchpadname[] = "scratchpad";
static const int nmaster      = 1;
