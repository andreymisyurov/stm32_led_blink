// General-Purpose Input/Output
typedef struct {
   volatile unsigned int MODER;   
   volatile unsigned int OTYPER;  
   volatile unsigned int OSPEEDR; 
   volatile unsigned int PUPDR;   
   volatile unsigned int IDR;     
   volatile unsigned int ODR;     
   volatile unsigned int BSRR;    
   volatile unsigned int LCKR;    
   volatile unsigned int AFR[2];  
} GPIO_Struct;

#define GPIOB_BASE 0x40020400UL
#define GPIOB ((GPIO_Struct *) GPIOB_BASE)

// shift for port A = 0, B = 1, C = 2
#define SHIFT_PORT_B 1
#define GPIOB_CLOCK_ENABLE (1 << SHIFT_PORT_B)
