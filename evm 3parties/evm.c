#include<avr/io.h>
#define F_CPU 8000000
#include<util/delay.h>
#include<lcdavr.h>
int a,b,c;//abc is generated internally so use lcd_number() to display them

int main()
{  int a=0;b=0;c=0;
    DDRB=0xff;//portb as output
    
	DDRD=0x00;
	//portd as input
	lcd_init();
	while(1)
	{ PORTD=0b11111000;
	
	   lcd_command(0x80);
	   lcd_string("press any key");
       
         if((PIND &0b11111000)==0b11101000)
		 {
		       // a=a+1;// a=party1 votes
				
				lcd_clear();
				
				lcd_command(0x80);
				lcd_string("  thank you");
				_delay_ms(20);
				
				lcd_clear();
				  a=a+1;
				}
	         if((PIND &0b11111000)==0b11011000)
			 {      //b=b+1;// b=party2 votes
			        
					lcd_clear();
					lcd_command(0x80);
					lcd_string("  thank you");
			     	_delay_ms(20);
			     	
				     lcd_clear();
			            b=b+1;// b=party2 votes  
						         }
              if((PIND &0b11111000)==0b10111000)
			  {
			      //  c=c+1;//party3 votes
                  
					lcd_clear();
					lcd_command(0x80);
					lcd_string("  thank you");
			     	_delay_ms(20);
			     	
				     lcd_clear();
					  c=c+1;//party3 votes
                  }
             if((PIND &0b11111000)==0b01111000)
			  {  //result
			     
					
				

			     if((a>>b) &&(a>>c))
				 {      lcd_clear();
				        lcd_command(0x80);
						lcd_string("  party 1 wins ");
						_delay_ms(20);   }
                 if((b>>a) &&(b>>c))
                   {      lcd_clear();
				        lcd_command(0x80);
						lcd_string("  party 2 wins ");
						_delay_ms(20);   }
               if((c>>a) &&(c>>b))
                   {      lcd_clear();
				        lcd_command(0x80);
						lcd_string("  party 3 wins ");
						_delay_ms(20);   }

                
					if((a==b))
						{
						   lcd_clear();
						   lcd_command(0x80);
						   lcd_string("part1=party2 votes");
						   _delay_ms(10);
						   lcd_clear();}

						   if((a==c))
						   {
						             lcd_clear();
						   lcd_command(0x80);
						   lcd_string("part1=party3 votes");
						   _delay_ms(10);
						   lcd_clear();}
                      if((b==c))
						 {
						        lcd_clear();
						   lcd_command(0x80);
						   lcd_string("part2=party3 votes");
						   _delay_ms(10);
						   lcd_clear();
                                                }


						        
						}
		       
        if((PIND & 0b11111000)==0b11110000)
		{
		      //reset
			  a=0;
			  b=0;
			  c=0;
			

			  }

              else { lcd_command(0x80);
	   lcd_string("press any key");
       }


	}
	
}
