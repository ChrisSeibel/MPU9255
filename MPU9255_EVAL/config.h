#ifndef CONFIG_H
#define CONFIG_H

//network
#define PI_IP "192.168.188.21"
#define PI_PORT 5000

#define PC_IP "192.168.188.24"
#define PC_PORT 5000

//camera
#define CAM_H_CHANNEL       0
#define CAM_H_MIN_ANGLE     35
#define CAM_H_MAX_ANGLE     135
#define CAM_H_MIN_PULSE     123
#define CAM_H_MAX_PULSE     500
#define CAM_H_HOME          90
#define CAM_H_OFFSET        -5

#define CAM_V_CHANNEL       1
#define CAM_V_MIN_ANGLE     20
#define CAM_V_MAX_ANGLE     175
#define CAM_V_MIN_PULSE     123
#define CAM_V_MAX_PULSE     500
#define CAM_V_HOME          90
#define CAM_V_OFFSET        3

//ESC
#define ESC_L_CHANNEL       2
#define ESC_L_MIN_LEN       1000
#define ESC_L_MAX_LEN       2000
#define ESC_L_MIN_PULSE     219
#define ESC_L_MAX_PULSE     438

#define ESC_R_CHANNEL       3
#define ESC_R_MIN_LEN       1000
#define ESC_R_MAX_LEN       2000
#define ESC_R_MIN_PULSE     219
#define ESC_R_MAX_PULSE     438

//MPU
#define MPU_READ_INTERVAL   200 //ms

#endif // CONFIG_H
