/**
 * This is the main test_input program file.
 */

#include "simpletools.h"

// Variables from comparing text from the terminal to these strings
char highin[5] = {"high"};
char lowin[4] = {"low"};
char inputtxt[3] = {"in"};
char ls[3] = {"ls"};
<<<<<<< HEAD
char digiwrite[3] = {"dw"};
=======
>>>>>>> master

char text[16];
int pins = 0;
int pincontainer;

<<<<<<< HEAD
int input_high(void);
int input_low(void);
int in(void);
int print_list(void);
int digital_write(void);
=======
void input_high(void);
void input_low(void);
void in(void);
void print_list(void);
>>>>>>> master

int main(void) {
  // Initialization
  // Set pins 12 to 17 to High Impendence mode
  print("Initialization\n");
  input(17);input(16);input(15);
  input(14);input(13);input(12);
  print("Pins 12 - 17 set to High Impendance mode. Those connections are safe.\n");
  print("To start press button.\n");
  while(input(0) == 0);                                                   // Wait until the button is pressed
  // Main loop
  while(1) {
    print("Type \"ls\" to view all functions.\n>> ");
    getStr(text,15);
    if (!strcmp(ls,text)) print_list();
    else if (!strcmp(inputtxt,text)) in();
    else if (!strcmp(highin,text)) input_high();
    else if (!strcmp(lowin,text)) input_low();
    else if (!strcmp(digiwrite,text)) digital_write();
  }    
  
  return 0;
}

/*************************************************
 * Prompts the user to type which pin to monitor *
 * and then continually display the input of that*
 * pin.                                          *
 *************************************************/
void in(void){
      pins = 0;
      print("Which pin: ");
      scan("%d\n",&pins);
      print("Monitoring pin %d until button is pressed\n", pins);
      int n = 0;
      while (n == 0) {
        print("Pin %d",pins);
        pincontainer = input(pins);
        print(" = %d\n",pincontainer);
        if (input(0) == 1) break;
        pause(100);
      }        
}

// Prints a list of the current commands
void print_list(void) {
  print("       Standard Commands\n");
  print("       =================\n");
  print("ls       ---       Display the current commands.\n\n");
  
  print("Read Commands\n");
  print("=============\n");
  print("in       ---       Show the input of a particular pin.\n");
  print("high     ---       Display the pins that have a voltage applied to them.\n");
  print("low      ---       Display the pins that have no voltage applied to them.\n");
}

// Shows all the pins that are floating high.
void input_high(void) {
  pins = 0;
  print("Pin 0 through  pin: ");
  scan("%d\n",&pins);
  while (pins >= 0) {
    print("Pin %d",pins);
    pincontainer = input(pins);
    print(" = %d\n",pincontainer);
    pins = pins - 1;
  }   
}

// Shows all the pins that are connected to ground
void input_low(void) {
  pins = 0;
  print("Pin 0 through pin: ");
  scan("%d\n",&pins);
  while (pins >= 0) {
    if (input(pins) == 0) {
      print("Pin %d\n",pins);
    }
    pins --;
<<<<<<< HEAD
  }
  return 0;           
}

int digital_write(void) {
  int sig = 0;
  pins = 0;
  int loop = 0;
  while (loop == 0) {
    print("What signal do you want to send (1 or 0): ");
    scan("%d\n",&sig);
        
    print("What pin: ");
    scan("%d\n",&pins);
    if (sig == 1) high(pins);
    else if(sig == 0) low(pins);
    else loop = 1; print("Error! Command only excepts the interger 1 or 0\n");
    loop = 1;                                         // Exit the loop
    print("Pin %d set to %d\n",pins,sig);
  }    
}  
=======
  }           
}
>>>>>>> master
