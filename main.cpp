#include <iostream>
#include <string>
#include <vector>

int Decoder(std::string input) {
   std::vector<int> numeralNumberValue;
   int total = 0;

   //Integer is added to the vector according to the user's valid input
   for (unsigned int i = 0; i < input.size(); ++i) {
      if (input.at(i) == 'I') { numeralNumberValue.push_back(1); }
      else if (input.at(i) == 'V') { numeralNumberValue.push_back(5); }
      else if (input.at(i) == 'X') { numeralNumberValue.push_back(10); }
      else if (input.at(i) == 'L') { numeralNumberValue.push_back(50); }
      else if (input.at(i) == 'C') { numeralNumberValue.push_back(100); }
      else if (input.at(i) == 'D') { numeralNumberValue.push_back(500); }
      else if (input.at(i) == 'M') { numeralNumberValue.push_back(1000); }
   }

   //Vector of integers are then compared to properly apply subtraction and addition conditions
   for (unsigned int i = 0; i < numeralNumberValue.size(); ++i) {
      if ((i + 1) < numeralNumberValue.size()) {
         if (numeralNumberValue.at(i) < numeralNumberValue.at(i + 1)) { total -= numeralNumberValue.at(i); }
         else { total += numeralNumberValue.at(i); }
      }
      else { total += numeralNumberValue.at(i); }
   }
   return total;
}

bool NumberOrderCheck(std::string input) {
   std::vector<int> checkNumberValue;
   bool orderCheck = false;

   for (unsigned int i = 0; i < input.size(); ++i) {
      if (input.at(i) == 'I') { checkNumberValue.push_back(1); }
      else if (input.at(i) == 'V') { checkNumberValue.push_back(5); }
      else if (input.at(i) == 'X') { checkNumberValue.push_back(10); }
      else if (input.at(i) == 'L') { checkNumberValue.push_back(50); }
      else if (input.at(i) == 'C') { checkNumberValue.push_back(100); }
      else if (input.at(i) == 'D') { checkNumberValue.push_back(500); }
      else if (input.at(i) == 'M') { checkNumberValue.push_back(1000); }
   }

   //The number in front is divided by the one preceding to establish a valid placement
   for (unsigned int i = 0; i < checkNumberValue.size(); ++i) {
      if ((i + 1) < checkNumberValue.size()) {
         if ((checkNumberValue.at(i + 1) / checkNumberValue.at(i)) <= 10) { orderCheck = false; }
         else { orderCheck = true; }
      }
   }

   return orderCheck;
}

int main(int argc, char* argv[]) {
   std::string userInput = "";
   int decodedNumber = 0;
   bool finalCheck = false;

   while (userInput != "quit") {
      std::cout << "Please enter your roman numeral to be decoded. (enter \"quit\" to exit)" << std::endl;
      getline(std::cin, userInput);
      finalCheck = NumberOrderCheck(userInput);

      if (finalCheck == false) { decodedNumber = Decoder(userInput); std::cout << "Your decoded number is: " << decodedNumber << std::endl;}
   }

   return 0;
}