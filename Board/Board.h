#ifndef STM32F4_BOARD
#define STM32F4_BOARD

#include "STM32F4_GPIO.h"
#include "STM32F4_TIM.h"
#include "STM32F4_UART.h"
#include "STM32F4_RCC.h"
#include "Dynamixel_control.h"
#include "Interrupts.h"

//--------------------------------------------- USART modules ------------------------------------------------//

#define DYNAMIXEL_USART_MODULE           UART4
#define DYNAMIXEL_USART_IRQN             UART4_IRQn
#define DYNAMIXEL_USART_BAUDRATE         1000000
#define DYNAMIXEL_USART_PIN_AF           GPIO_AF_UART4
#define DYNAMIXEL_USART_TX_PIN_PORT      GPIOC
#define DYNAMIXEL_USART_TX_PIN_NUMBER    GPIO_Pin_10
#define DYNAMIXEL_USART_RX_PIN_PORT      GPIOC
#define DYNAMIXEL_USART_RX_PIN_NUMBER    GPIO_Pin_11

//#define DEBUG_USART_MODULE               USART1
//#define DEBUG_USART_IRQN                 USART1_IRQn
//#define DEBUG_USART_BAUDRATE             9600
//#define DEBUG_USART_PIN_AF               GPIO_AF_USART1
//#define DEBUG_USART_TX_PIN_PORT          GPIOB
//#define DEBUG_USART_TX_PIN_NUMBER        GPIO_Pin_6
//#define DEBUG_USART_RX_PIN_PORT          GPIOB
//#define DEBUG_USART_RX_PIN_NUMBER        GPIO_Pin_7

#define COM_USART_MODULE                 USART1
#define COM_USART_IRQN                   USART1_IRQn
#define COM_USART_BAUDRATE               64000
#define COM_USART_PIN_AF                 GPIO_AF_USART1
#define COM_USART_TX_PIN_PORT            GPIOB
#define COM_USART_TX_PIN_NUMBER          GPIO_Pin_6
#define COM_USART_RX_PIN_PORT            GPIOB
#define COM_USART_RX_PIN_NUMBER          GPIO_Pin_7

//--------------------------------------------- Encoders -----------------------------------------------------//
// Initial value for TIM->CNT register (30000)
#define ENCODER_CNT_INITIAL_VALUE        0x7530

#define ENCODER_4_TIM_MODULE             TIM8
#define ENCODER_4_CHA_PORT               GPIOC
#define ENCODER_4_CHA_PIN                GPIO_Pin_7
#define ENCODER_4_CHB_PORT               GPIOC
#define ENCODER_4_CHB_PIN                GPIO_Pin_6
#define ENCODER_4_PIN_AF                 GPIO_AF_TIM8
#define ENCODER_4_CNT                    ((uint16_t *)&(ENCODER_4_TIM_MODULE->CNT))

#define ENCODER_3_TIM_MODULE             TIM1
#define ENCODER_3_CHA_PORT               GPIOE
#define ENCODER_3_CHA_PIN                GPIO_Pin_11
#define ENCODER_3_CHB_PORT               GPIOE
#define ENCODER_3_CHB_PIN                GPIO_Pin_9
#define ENCODER_3_PIN_AF                 GPIO_AF_TIM1
#define ENCODER_3_CNT                    ((uint16_t *)&(ENCODER_3_TIM_MODULE->CNT))

#define ENCODER_2_TIM_MODULE             TIM3
#define ENCODER_2_CHA_PORT               GPIOA
#define ENCODER_2_CHA_PIN                GPIO_Pin_6
#define ENCODER_2_CHB_PORT               GPIOA
#define ENCODER_2_CHB_PIN                GPIO_Pin_7
#define ENCODER_2_PIN_AF                 GPIO_AF_TIM3
#define ENCODER_2_CNT                    ((uint16_t *)&(ENCODER_2_TIM_MODULE->CNT))

#define ENCODER_1_TIM_MODULE             TIM2
#define ENCODER_1_CHA_PORT               GPIOB
#define ENCODER_1_CHA_PIN                GPIO_Pin_3
#define ENCODER_1_CHB_PORT               GPIOA
#define ENCODER_1_CHB_PIN                GPIO_Pin_15
#define ENCODER_1_PIN_AF                 GPIO_AF_TIM2
#define ENCODER_1_CNT                    ((uint16_t *)&(ENCODER_1_TIM_MODULE->CNT))

//--------------------------------------------- Motor PWM control  --------------------------------------------------//

// ARR = 42000, PSC = 2, fapb1 = 42 MHZ, PWM frequency = 1000 Hz
#define MOTOR_PWM_TIM_MODULE             TIM4
#define MOTOR_PWM_TIM_PSC                0x02
#define MOTOR_PWM_TIM_ARR                0xA410
#define MOTOR_PWM_PIN_AF                 GPIO_AF_TIM4

#define MOTOR_CH1_NUMBER                 0x01
#define MOTOR_CH2_NUMBER                 0x02
#define MOTOR_CH3_NUMBER                 0x03
#define MOTOR_CH4_NUMBER                 0x04

#define MOTOR_CH_PWM_PORT                GPIOD
#define MOTOR_CH1_PWM_PIN                GPIO_Pin_12
#define MOTOR_CH2_PWM_PIN                GPIO_Pin_13
#define MOTOR_CH3_PWM_PIN                GPIO_Pin_14
#define MOTOR_CH4_PWM_PIN                GPIO_Pin_15

#define MOTOR_CH1_DIR_PORT               GPIOC
#define MOTOR_CH1_DIR_PIN                GPIO_Pin_14
#define MOTOR_CH2_DIR_PORT               GPIOC
#define MOTOR_CH2_DIR_PIN                GPIO_Pin_15
#define MOTOR_CH3_DIR_PORT               GPIOE
#define MOTOR_CH3_DIR_PIN                GPIO_Pin_10
#define MOTOR_CH4_DIR_PORT               GPIOE
#define MOTOR_CH4_DIR_PIN                GPIO_Pin_14

#define MOTOR_CH1_EN_PORT                GPIOC
#define MOTOR_CH1_EN_PIN                 GPIO_Pin_14
#define MOTOR_CH2_EN_PORT                GPIOC
#define MOTOR_CH2_EN_PIN                 GPIO_Pin_15
#define MOTOR_CH3_EN_PORT                GPIOE
#define MOTOR_CH3_EN_PIN                 GPIO_Pin_10
#define MOTOR_CH4_EN_PORT                GPIOE
#define MOTOR_CH4_EN_PIN                 GPIO_Pin_14

//--------------------------------------------- Timer for motor control (100 Hz) ------------------------------------------------//

// ARR = 42000, PSC = 20, fapb1 = 42 MHZ, Frequency = 100 Hz
#define MOTOR_CONTROL_TIM_MODULE         TIM6
#define MOTOR_CONTROL_TIM_PSC            0x14
#define MOTOR_CONTROL_TIM_ARR            0xA410
#define MOTOR_CONTROL_IRQN               TIM6_DAC_IRQn
#define MOTOR_CONTROL_PERIOD             0.01f
#define MOTOR_CONTROL_CALC_COEF          MOTOR_CONTROL_PERIOD/MOTOR_CONTROL_TIM_ARR

//--------------------------------------------- Timer for manipulators control (100 Hz) ----------------------------------------//

// ARR = 42000, PSC = 20, fapb1 = 42 MHZ, Frequency = 100 Hz
#define SERVO_CHECKER_TIM_MODULE         TIM5
#define SERVO_CHECKER_TIM_PSC            0x14
#define SERVO_CHECKER_TIM_ARR            0xA410
#define SERVO_CHECKER_IRQN               TIM5_IRQn
#define SERVO_CHECKER_PERIOD             0.01f
#define SERVO_CHECKER_TICKS_TO_SEC       0.00000238f

//--------------------------------------------- Enable pin for communication with servos ---------------------------------------//

// Pin turns microchip for communication with servos (0 - transmitting data, 1 - receiving data)
#define DYNAMIXEL_SIGNAL_EN_PIN          GPIO_Pin_12
#define DYNAMIXEL_SIGNAL_EN_PORT         GPIOB


// Initialize all necessary peripheral devices
void boardInitAll(void);

#endif
