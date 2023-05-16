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
#include "LCD.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
void keypad_tara();
void ekran_guncelle();
void ekran_resetle();
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t mevcut_rakam = 0;
uint16_t p_sayi = 0;
const uint16_t SIFRE = 1234;
uint16_t girilen_sifre[4] = {0};
uint16_t sifre = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

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
  /* USER CODE BEGIN 2 */
  lcd_init(_LCD_4BIT, _LCD_FONT_5x8, _LCD_2LINE); // lcdyi başlat ve ekrana şifre girmek için gereken menüyü yazdır.
  lcd_clear();
  lcd_print(1, 1, "SIFRE GIRINIZ:");
  lcd_print(2, 1, "0000");


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  keypad_tara(); // keypad tarama fonksiyonunu çağır ----> tüm işlemler bu fonksiyonun içinde yapılıyor.
	  HAL_Delay(100); // karışıklık olmaması için 100ms bekle.

  }
  /* USER CODE END 3 */
}

void keypad_tara(){
	/*1. Sütun Tarama*/
	HAL_GPIO_WritePin(COL1_GPIO_Port, COL1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(COL2_GPIO_Port, COL2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(COL3_GPIO_Port, COL3_Pin, GPIO_PIN_RESET);

	if(HAL_GPIO_ReadPin(ROWA_GPIO_Port, ROWA_Pin)){ //eğer a sütunu 1 ise
		mevcut_rakam = 1;							// basılan tuş 1dir
		ekran_guncelle();							// ekran güncelle fonksiyonunu çağır.
		while(HAL_GPIO_ReadPin(ROWA_GPIO_Port, ROWA_Pin)); // hala 1e tuşuna basılı ise bırakılana kadar bekle. tuş bırakıldığında programa devam et.

	}else if(HAL_GPIO_ReadPin(ROWB_GPIO_Port, ROWB_Pin)){  // diğer tüm tuşlar için aynı işlem geçerli.
		mevcut_rakam = 4;
		ekran_guncelle();
		while(HAL_GPIO_ReadPin(ROWB_GPIO_Port, ROWB_Pin));

	}else if(HAL_GPIO_ReadPin(ROWC_GPIO_Port, ROWC_Pin)){
		mevcut_rakam = 7;
		ekran_guncelle();
		while(HAL_GPIO_ReadPin(ROWC_GPIO_Port, ROWC_Pin));

	}else if(HAL_GPIO_ReadPin(ROWD_GPIO_Port, ROWD_Pin)){
		//mevcut_rakam = 10; // * tuşuna bir işlem atanmadığı için boş bırakıldı.
		//ekran_guncelle();
		//while(HAL_GPIO_ReadPin(ROWD_GPIO_Port, ROWD_Pin));

	}

	/*2. Sütun Tarama*/
	HAL_GPIO_WritePin(COL1_GPIO_Port, COL1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(COL2_GPIO_Port, COL2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(COL3_GPIO_Port, COL3_Pin, GPIO_PIN_RESET);

	if(HAL_GPIO_ReadPin(ROWA_GPIO_Port, ROWA_Pin)){
		mevcut_rakam = 2;
		ekran_guncelle();
		while(HAL_GPIO_ReadPin(ROWA_GPIO_Port, ROWA_Pin));

	}else if(HAL_GPIO_ReadPin(ROWB_GPIO_Port, ROWB_Pin)){
		mevcut_rakam = 5;
		ekran_guncelle();
		while(HAL_GPIO_ReadPin(ROWB_GPIO_Port, ROWB_Pin));

	}else if(HAL_GPIO_ReadPin(ROWC_GPIO_Port, ROWC_Pin)){
		mevcut_rakam = 8;
		ekran_guncelle();
		while(HAL_GPIO_ReadPin(ROWC_GPIO_Port, ROWC_Pin));

	}else if(HAL_GPIO_ReadPin(ROWD_GPIO_Port, ROWD_Pin)){
		mevcut_rakam = 0;
		ekran_guncelle();
		while(HAL_GPIO_ReadPin(ROWD_GPIO_Port, ROWD_Pin));

	}

	/*3. Sütun Tarama*/
	HAL_GPIO_WritePin(COL1_GPIO_Port, COL1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(COL2_GPIO_Port, COL2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(COL3_GPIO_Port, COL3_Pin, GPIO_PIN_SET);

	if(HAL_GPIO_ReadPin(ROWA_GPIO_Port, ROWA_Pin)){
		mevcut_rakam = 3;
		ekran_guncelle();
		while(HAL_GPIO_ReadPin(ROWA_GPIO_Port, ROWA_Pin));

	}else if(HAL_GPIO_ReadPin(ROWB_GPIO_Port, ROWB_Pin)){
		mevcut_rakam = 6;
		ekran_guncelle();
		while(HAL_GPIO_ReadPin(ROWB_GPIO_Port, ROWB_Pin));

	}else if(HAL_GPIO_ReadPin(ROWC_GPIO_Port, ROWC_Pin)){
		mevcut_rakam = 9;
		ekran_guncelle();
		while(HAL_GPIO_ReadPin(ROWC_GPIO_Port, ROWC_Pin));

	}else if(HAL_GPIO_ReadPin(ROWD_GPIO_Port, ROWD_Pin)){
		//mevcut_rakam = 11; // # tuşu
		ekran_resetle();     // diğer tuşlardan farklı olarak bu tuşa basılırsa mevcut girilmiş şifre resetleniyor ve baştan şifre girilmesi sağlanıyor
		while(HAL_GPIO_ReadPin(ROWD_GPIO_Port, ROWD_Pin));

	}

}

void ekran_guncelle(){

	/*girilen_sifre dizisi 4 elemanlı, bastığımız her tuşu bir indeksinde tutan bir dizidir*/

	girilen_sifre[p_sayi] = mevcut_rakam; // basılan tuşu dizinin sıradaki indeksine atıyoruz


	lcd_clear();  // her bir yeni tuşa basıldığında ekranı temizlememiz gerekiyor
	char ekran[16]; // ekrana birden fazla rakam yazacağımz için ekran adında bir karakter dizisi oluşturduk
	sprintf(ekran, "%d%d%d%d", girilen_sifre[0], girilen_sifre[1], girilen_sifre[2], girilen_sifre[3]); // bu karakter dizisine, her bir basılan tuşun değeri yazılır
	lcd_print(1, 1, "SIFRE GIRINIZ:");
	lcd_print(2, 1, ekran); // karakter dizisi ekranın alt satırına yazdırılır
	p_sayi++; // bir sonraki gelecek karakter için p_sayi değişkeni bir arttırılır.

	if(p_sayi >= 4){ // eğer p_sayi değişkeni 4 olmuş ise 4 basamaklı sayı girilmiş demektir.
		/* alt satırda, aldığımız her bir rakamı, basamak değerleriyle çarpıp, birbirleriyle toplayarak asıl girilen sayıyı hesaplıyoruz*/
		sifre = girilen_sifre[0]*1000 + girilen_sifre[1]*100 + girilen_sifre[2]*10 + girilen_sifre[3]*1;

		if (sifre == SIFRE){ // eğer hesapladığımız sayı belirli olan şifremize eşit ise girilen şfire doğru demektir
			HAL_Delay(500);  // 500ms bekliyoruz ki kullanıcı şifreyi girdiğini görebilsin
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET); // şifre doğru olduğu için led yanıyor
			lcd_clear();    // ekranda hoş geldiniz yazısı gösteriliyor.
			lcd_print(1, 1, "      HOS");
			lcd_print(2, 1, "    GELDINIZ");
			HAL_Delay(2000); // 2 sn bekleniyor
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET); // 2sn sonunda led söndürülüyor ve ekra yeni şifre giilmesi için başlangıç haline döndürülüyor.
			lcd_clear();
			lcd_print(1, 1, "SIFRE GIRINIZ:");
			lcd_print(2, 1, "0000");
		}else{				// eğer girilen şifre yanlış ise ekranda şifre yanlış yazısı çıkıyor ve 2sn sonra başlangıç ekranına geri dönülüyor.
			lcd_clear();
			lcd_print(1, 1, "    SIFRE");
			lcd_print(2, 1, "    YANLIS");
			HAL_Delay(2000);
			lcd_clear();
			lcd_print(1, 1, "SIFRE GIRINIZ:");
			lcd_print(2, 1, "0000");
		}

		/* şifre doğru ya da yanlış olsun, arka arkaya 4 tuşa basıldıktan sonra, hesaplamanın doğru yapılabilmesi için tüm değişkenler sıfırlanıyor.*/
		p_sayi = 0;
		sifre = 0;
		girilen_sifre[0] = 0;
		girilen_sifre[1] = 0;
		girilen_sifre[2] = 0;
		girilen_sifre[3] = 0;
	}

}

void ekran_resetle(){
	/* tüm değişkenler sıfırlanıyor ve ekran başlangıç haline döndürülüyor.*/
	lcd_clear();
	lcd_print(1, 1, "SIFRE GIRINIZ:");
	lcd_print(2, 1, "0000");
	p_sayi = 0;
	sifre = 0;
	girilen_sifre[0] = 0;
	girilen_sifre[1] = 0;
	girilen_sifre[2] = 0;
	girilen_sifre[3] = 0;
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
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV16;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
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
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LCD_EN_Pin|LCD_RS_Pin|LCD_D4_Pin|LCD_D5_Pin
                          |LCD_D6_Pin|LCD_D7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, COL1_Pin|COL2_Pin|COL3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED_Pin */
  GPIO_InitStruct.Pin = LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_EN_Pin LCD_RS_Pin LCD_D4_Pin LCD_D5_Pin
                           LCD_D6_Pin LCD_D7_Pin */
  GPIO_InitStruct.Pin = LCD_EN_Pin|LCD_RS_Pin|LCD_D4_Pin|LCD_D5_Pin
                          |LCD_D6_Pin|LCD_D7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : COL1_Pin COL2_Pin COL3_Pin */
  GPIO_InitStruct.Pin = COL1_Pin|COL2_Pin|COL3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : ROWA_Pin ROWB_Pin ROWC_Pin ROWD_Pin */
  GPIO_InitStruct.Pin = ROWA_Pin|ROWB_Pin|ROWC_Pin|ROWD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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
