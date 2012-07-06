// 常數定義檔
// 定義一些硬體介面用的設定
// Const.h
// Definitions file
// Comm port type
#define PORT_USB 0
#define PORT_COM1 1
#define PORT_COM2 2
#define PORT_COM3 3
#define PORT_COM4 4
#define PORT_COM5 5
#define PORT_COMMAX 255
// CA display mode
#define DSP_LXY 0
#define DSP_DUV 1
#define DSP_ANL 2
#define DSP_ANLG 3
#define DSP_ANLR 4
#define DSP_PUV 5
#define DSP_FMA 6
#define DSP_XYZC 7
#define DSP_JEITA 8
#define DSP_XYZ 9
// CA sync mode
#define SYNC_NTSC 0
#define SYNC_PAL 1
#define SYNC_EXT 2
#define SYNC_UNIV 3
#define SYNC_INT 4
// CA display digits
#define DIGT_3 0
#define DIGT_4 1
// CAFAST/SLOW setting
#define AVRG_SLOW 0
#define AVRG_FAST 1
#define AVRG_AUTO 2
// CA luminance units
#define BUNIT_FL 0
#define BUNIT_CD 1
// Konica Minolta calibration standard
#define CAL_D65 1
#define CAL_9300 2
#define CAL_CA100 3
// CA type
#define CATYPE_210 0
#define CATYPE_210S 1
#define CATYPE_100PLUS 2
#define CATYPE_200 3
// Probe type
#define PROBETYPE_CA100PLUS 1001
#define PROBETYPE_CA100PLUSH 1002
#define PROBETYPE_CA210 2100
#define PROBETYPE_CA210S 2101
// Remote mode
#define REMOTE_OFF 0
#define REMOTE_ON 1
#define REMOTE_LOCK 2
// Reference color
#define CAL_RED 0
#define CAL_GREEN 1
#define CAL_BLUE 2
#define CAL_WHITE 3