/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
CAN_HandleTypeDef hcan;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CAN_Init(void);
/* USER CODE BEGIN PFP */
CAN_TxHeaderTypeDef   TxHeader;
CAN_RxHeaderTypeDef   RxHeader;
CAN_FilterTypeDef  		sFilterConfig;

uint8_t TxData[8];
uint8_t RxData[8];

uint32_t TxMailbox;

void CanTx_Init(void){
	//================can tx===================//
	TxHeader.StdId = 0x7A2;//dia chi cua can
	TxHeader.RTR = CAN_RTR_DATA;
	TxHeader.IDE = CAN_ID_STD;
	TxHeader.DLC = 8;	//so byte truyen di
	TxHeader.TransmitGlobalTime = DISABLE;
	HAL_CAN_Start(&hcan);
}
void CanRx_Init_Mask()
{
	//=================can filter==============//
	/* -------------------------------id 0X103 ----------------------------------*/
	sFilterConfig.FilterBank = 0;
	sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
	sFilterConfig.FilterIdHigh = 0x7AA<<5;
	sFilterConfig.FilterIdLow = 0;
	sFilterConfig.FilterMaskIdHigh = 0x7AA<<5;
	sFilterConfig.FilterMaskIdLow = 0;
	sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
	sFilterConfig.FilterActivation = ENABLE;
	HAL_CAN_ConfigFilter(&hcan, &sFilterConfig);
	//==================cho phep can hoat dong=================//
	HAL_CAN_Start(&hcan);
	//==================kich hoat ngat can=====================//
	HAL_CAN_ActivateNotification(&hcan,CAN_IT_RX_FIFO0_MSG_PENDING);
}



 		void CanRx_Init_List()
		{
			//=================can filter==============//
			/* -------------------------------id 0X103 ----------------------------------*/
			sFilterConfig.FilterBank = 0;
			sFilterConfig.FilterMode = CAN_FILTERMODE_IDLIST;
			sFilterConfig.FilterScale = CAN_FILTERSCALE_16BIT;
			sFilterConfig.FilterIdHigh = 0x104<<5;  // chỉ nhận dữ liệu từ node 0x104
			sFilterConfig.FilterIdLow = 0;
			sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
			sFilterConfig.FilterActivation = ENABLE;
			HAL_CAN_ConfigFilter(&hcan, &sFilterConfig);
			//==================cho phep can hoat dong=================//
			HAL_CAN_Start(&hcan);
			//==================kich hoat ngat can=====================//
			HAL_CAN_ActivateNotification(&hcan,CAN_IT_RX_FIFO0_MSG_PENDING);
		}

 		void CanRx_Init_List1()
		{
			//=================can filter==============//
			/* -------------------------------id 0X103 ----------------------------------*/
			sFilterConfig.FilterBank = 1;
			sFilterConfig.FilterMode = CAN_FILTERMODE_IDLIST;
			sFilterConfig.FilterScale = CAN_FILTERSCALE_16BIT;
			sFilterConfig.FilterIdHigh = 0x446<<5;  // chỉ nhận dữ liệu từ node 0x446
			sFilterConfig.FilterIdLow = 0;
			sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
			sFilterConfig.FilterActivation = ENABLE;
			HAL_CAN_ConfigFilter(&hcan, &sFilterConfig);
			//==================cho phep can hoat dong=================//
			HAL_CAN_Start(&hcan);
			//==================kich hoat ngat can=====================//
			HAL_CAN_ActivateNotification(&hcan,CAN_IT_RX_FIFO0_MSG_PENDING);
		}

///////
void Send_Buffer(unsigned char data0, unsigned char data1, unsigned char data2, unsigned char data3, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7){
   TxData[0] = data0;
   TxData[1] = data1;
   TxData[2] = data2;
   TxData[3] = data3;
   TxData[4] = data4;
   TxData[5] = data5;
   TxData[6] = data6;
   TxData[7] = data7;
   HAL_CAN_AddTxMessage(&hcan, &TxHeader, TxData, &TxMailbox);
}
//
void Send_CAN(){
	switch (~(GPIOA->IDR) & 0xFF){
		case 0x01:
			TxHeader.StdId = 0x7A2;
			HAL_CAN_Start(&hcan);
			Send_Buffer(0x04, 0x2E, 0xB0, 0x06, 0x01, 0x00, 0x00, 0);
			break;
		case 0x02:
			TxHeader.StdId = 0x7A2;
			HAL_CAN_Start(&hcan);
			Send_Buffer(0x04, 0x2E, 0xB0, 0x06, 0x02, 0x00, 0x00, 0);
			break;
		case 0x04:
			TxHeader.StdId = 0x7A2;
			HAL_CAN_Start(&hcan);
			Send_Buffer(0x04, 0x2E, 0xB0, 0x06, 0x03, 0x00, 0x00, 0);
			break;
		case 0x08:
			TxHeader.StdId = 0x2df;
			HAL_CAN_Start(&hcan);
			Send_Buffer(0xFF, 0, 0, 0x10, 0x0, 0x0, 0x00, 0x00);
			break;
		case 0x10:
			TxHeader.StdId = 0x2df;
			HAL_CAN_Start(&hcan);
			Send_Buffer(0x0, 0x0, 0xfe, 0x13, 0x0, 0x0, 0x00, 0x00);

			break;
		case 0x20:
			TxHeader.StdId = 0x2df;
			HAL_CAN_Start(&hcan);
			Send_Buffer(0x0, 0xfe, 0x01, 0x10, 0x0, 0x0, 0x00, 0x00);

			break;
		case 0x40:
			TxHeader.StdId = 0x2df;
			HAL_CAN_Start(&hcan);
			Send_Buffer(0xFF, 0xFE, 0xfd, 0x13, 0x0, 0x0, 0x00, 0x00);

			break;
		case 0x80:
			TxHeader.StdId = 0x2df;
			HAL_CAN_Start(&hcan);
			Send_Buffer(0x00, 0x00, 0x0, 0x08, 0x0, 0x0, 0x00, 0x00);
			break;
		default:
			break;
	}
//	if((!HAL_GPIO_ReadPin(GPIOA, dang_ky_A0_Pin))||(!HAL_GPIO_ReadPin(GPIOA, scan_A1_Pin))||(!HAL_GPIO_ReadPin(GPIOA, delete_A2_Pin))){
//		TxHeader.StdId = 0x7A2;
//		HAL_CAN_Start(&hcan);
//		if(!HAL_GPIO_ReadPin(GPIOA, dang_ky_A0_Pin))	Send_Buffer(0x04, 0x2E, 0xB0, 0x06, 0x01, 0x00, 0x00, 0);
//		if(!HAL_GPIO_ReadPin(GPIOA, scan_A1_Pin))	    Send_Buffer(0x04, 0x2E, 0xB0, 0x06, 0x02, 0x00, 0x00, 0);
//		if(!HAL_GPIO_ReadPin(GPIOA, delete_A2_Pin))	    Send_Buffer(0x04, 0x2E, 0xB0, 0x06, 0x03, 0x00, 0x00, 0);
//	}
//	if((!HAL_GPIO_ReadPin(GPIOA, led_red_A3_Pin))||(!HAL_GPIO_ReadPin(GPIOA, led_blue_A5_Pin))||(!HAL_GPIO_ReadPin(GPIOA, led_green_A4_Pin))||(!HAL_GPIO_ReadPin(GPIOA, led_white_A6_GPIO_Port))||(!HAL_GPIO_ReadPin(GPIOA, led_off_A7_Pin))) {
//		TxHeader.StdId = 0x2df;
//		HAL_CAN_Start(&hcan);
//		if(!HAL_GPIO_ReadPin(GPIOA, led_red_A3_Pin))	    Send_Buffer(0xFF, 0, 0, 0x10, 0x0, 0x0, 0x00, 0x00);
//		if(!HAL_GPIO_ReadPin(GPIOA, led_blue_A5_Pin))	    Send_Buffer(0x0, 0x0, 0xfe, 0x13, 0x0, 0x0, 0x00, 0x00);
//		if(!HAL_GPIO_ReadPin(GPIOA, led_green_A4_Pin))	    Send_Buffer(0x0, 0xfe, 0x01, 0x10, 0x0, 0x0, 0x00, 0x00);
//		if(!HAL_GPIO_ReadPin(GPIOA, led_white_A6_Pin))	    Send_Buffer(0xFF, 0xFE, 0xfd, 0x13, 0x0, 0x0, 0x00, 0x00);
//		if(!HAL_GPIO_ReadPin(GPIOA, led_off_A7_Pin))	    Send_Buffer(0x00, 0x00, 0x0, 0x08, 0x0, 0x0, 0x00, 0x00);
//	}

}

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CAN_Init();
  /* USER CODE BEGIN 2 */
  CanTx_Init();
  CanRx_Init_Mask();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  //Send_Buffer(0x04, 0x2E, 0xB0, 0x06, 0x01, 0x00, 0x00, 0);
  while (1)
  {

    /* USER CODE END WHILE */
	  Send_CAN();
    /* USER CODE BEGIN 3 */
//	  HAL_CAN_AddTxMessage(&hcan, &TxHeader, TxData, &TxMailbox); //
	  //HAL_Delay(200);
	  //Send_Buffer(0x04, 0x2E, 0x2E, 0xB0, 0x06, 0x01, 0x00, 0x00);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief CAN Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN_Init(void)
{

  /* USER CODE BEGIN CAN_Init 0 */

  /* USER CODE END CAN_Init 0 */

  /* USER CODE BEGIN CAN_Init 1 */

  /* USER CODE END CAN_Init 1 */
  hcan.Instance = CAN1;
  hcan.Init.Prescaler = 4;
  hcan.Init.Mode = CAN_MODE_NORMAL;
  hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan.Init.TimeSeg1 = CAN_BS1_15TQ;
  hcan.Init.TimeSeg2 = CAN_BS2_2TQ;
  hcan.Init.TimeTriggeredMode = DISABLE;
  hcan.Init.AutoBusOff = DISABLE;
  hcan.Init.AutoWakeUp = DISABLE;
  hcan.Init.AutoRetransmission = DISABLE;
  hcan.Init.ReceiveFifoLocked = DISABLE;
  hcan.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN_Init 2 */

  /* USER CODE END CAN_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : dang_ky_A0_Pin scan_A1_Pin delete_A2_Pin led_red_A3_Pin
                           led_green_A4_Pin led_blue_A5_Pin led_white_A6_Pin led_off_A7_Pin */
  GPIO_InitStruct.Pin = dang_ky_A0_Pin|scan_A1_Pin|delete_A2_Pin|led_red_A3_Pin
                          |led_green_A4_Pin|led_blue_A5_Pin|led_white_A6_Pin|led_off_A7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */