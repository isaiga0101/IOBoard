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
char scriptmode[4] = {"scr"};
=======

>>>>>>> master
char text[16];
int pins = 0;
int pincontainer;

int input_high(void);
int input_low(void);
int in(void);
int print_list(void);
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
  }    
  
  return 0;
}

/*************************************************
 * Prompts the user to type which pin to monitor *
 * and then continually display the input of that*
 * pin.                                          *
 *************************************************/
int in(void){
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
      return 0;        
}

// Prints a list of the current commands
int print_list(void) {
  print("       Standard Commands\n");
  print("       =================\n");
  print("ls       ---       Display the current commands.\n\n");
  
  print("Read Commands\n");
  print("=============\n");
  print("in       ---       Show the input of a particular pin.\n");
  print("high     ---       Display the pins that have a voltage applied to them.\n");
  print("low      ---       Display the pins that have no voltage applied to them.\n");
  return 0;
}

// Shows all the pins that are floating high.
int input_high(void) {
  pins = 0;
  print("Pin 0 through  pin: ");
  scan("%d\n",&pins);
  while (pins >= 0) {
    print("Pin %d",pins);
    pincontainer = input(pins);
    print(" = %d\n",pincontainer);
    pins = pins - 1;
  }
  return 0;    
}

// Shows all the pins that are connected to ground
int input_low(void) {
  pins = 0;
  print("Pin 0 through pin: ");
  scan("%d\n",&pins);
  while (pins >= 0) {
    if (input(pins) == 0) {
      print("Pin %d\n",pins);
    }
    pins --;
  }
  return 0;           
}