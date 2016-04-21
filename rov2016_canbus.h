/**
  **************************************************************************************
  * @file    rov2016_canbus.h
  * @author  Sivert Sliper, Stian Soerensen
  * @version V1.0
  * @date    3-February-2016
  * @brief   This file contains local variables and macros for rov2016_canbus.c
  **************************************************************************************
  */

/* Include -----------------------------------------------------------------------------*/

/* Private macro -----------------------------------------------------------------------*/
#define CAN_ID_TYPE_STD						0u
#define CAN_ID_TYPE_EXT						4u

/* ID list, RANGE = [0...0x7FF] *********************************************************/
typedef enum {
	CAN_PACKET_SET_DUTY = 0,
	CAN_PACKET_SET_CURRENT,
	CAN_PACKET_SET_CURRENT_BRAKE,
	CAN_PACKET_SET_RPM,
	CAN_PACKET_SET_POS,
	CAN_PACKET_FILL_RX_BUFFER,
	CAN_PACKET_FILL_RX_BUFFER_LONG,
	CAN_PACKET_PROCESS_RX_BUFFER,
	CAN_PACKET_PROCESS_SHORT_BUFFER,
	CAN_PACKET_STATUS,
	CAN_PACKET_GET_CURRENT,
	CAN_PACKET_GET_RPM,
	CAN_PACKET_GET_TEMP_VOLT
} CAN_PACKET_ID;

#define TOP_BASE 						0x200
#define TOP_XBOX_CTRLS					TOP_BASE
#define TOP_XBOX_AXES					(TOP_BASE + 1)
#define TOP_POWR_CTRL					(TOP_BASE + 2)

#define SENSOR_BASE 					0x300
#define SENSOR_AN_RAW					SENSOR_BASE
#define SENSOR_PROCESSED_DATA			(SENSOR_BASE + 1)
#define SENSOR_ACCELERATION				(SENSOR_BASE + 2)
#define SENSOR_DEPTH_TEMP				(SENSOR_BASE + 3)
#define SENSOR_LEAKAGE_ALARM			(SENSOR_BASE + 4)
#define SENSOR_AHRS_QUATERNIONS			(SENSOR_BASE + 5)
#define SENSOR_ALIVE					(SENSOR_BASE + 6)
#define SENSOR_AHRS						(SENSOR_BASE + 7)
#define SENSOR_CURR_TEST				(SENSOR_BASE + 8)

#define POWR_BASE 						0x400
#define POWR_THR_CURRENT				POWR_BASE
#define POWR_MAN_CURRENT				(POWR_BASE + 1)
#define POWR_ALIVE					(POWR_BASE + 2)
#define POWR_CAM_PWM					(POWR_BASE + 3)


#define VESC_BASE						0x500
#define VESC_CURRENT_BASE				0x500
#define VESC_RPM_BASE					0x510
#define VESC_TEMP_VOLT_BASE				0x520

/* Exported function prototypes --------------------------------------------------------*/
extern void CAN_init(void);
extern uint8_t CAN_getByteFromMessage(uint8_t filter_number, uint8_t byte_number);
extern uint8_t CAN_getRxMessages(void);
extern void CAN_transmitBuffer(uint32_t Id, uint8_t* buffer, uint8_t length, uint8_t Id_Type);
extern void CAN_transmitByte(uint16_t StdId, uint8_t data);
extern void CAN_transmitByte_EID(uint32_t EID, uint8_t data);
extern uint8_t* CAN_getMessagePointer(uint8_t filter_number);
extern uint8_t CAN_addRxFilter(uint16_t StdId);
extern void CAN_deleteRxByte(uint8_t fmi, uint8_t byte_number);


