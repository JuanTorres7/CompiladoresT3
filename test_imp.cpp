#include <sstream>
#include <iostream>
#include <iostream>
#include "imp.hh"
#include "imp_parser.hh"
#include "imp_printer.hh"
#include "imp_interpreter.hh"
#include "imp_typechecker.hh"

int main(int argc, const char* argv[]) {
  /*
  Program *program; 
   
  if (argc != 2) {
    cout << "Incorrect number of arguments" << endl;
    exit(1);
  }

  std::ifstream t(argv[1]);
  std::stringstream buffer;
  buffer << t.rdbuf();
  Scanner scanner(buffer.str());
  
  Parser parser(&scanner);
  program = parser.parse();  // el parser construye la aexp
  
  ImpPrinter printer;
  ImpInterpreter interpreter;
  ImpTypeChecker checker;

  
  printer.print(program);
  
  cout << endl << "Type checking:" << endl;
  checker.typecheck(program);
  
  cout << endl << "Run program:" << endl;
  interpreter.interpret(program);


  delete program;
  */

  // Testing True/False, And/Or sentence and For-Do loop
  if (argc < 2) {
    cout << "Incorrect number of arguments" << endl;
    exit(1);
  }

  ImpPrinter printer;
  ImpInterpreter interpreter;
  ImpTypeChecker checker;

  for (int i = 1; i < argc; i++) {
    const char* filename = argv[i];

    ifstream f(filename);
    if (!f.is_open()) {
      std::cerr << "Failed to open file: " << filename << std::endl;
      continue;
    }
    stringstream buffer;
    buffer << f.rdbuf();
    Scanner scanner(buffer.str());

    Parser parser(&scanner);
    Program* program = parser.parse();

    if (program) {
      cout << endl << "Parsing result for " << filename << ":" << endl;
      cout << endl << "Program: " << filename << ":" << endl;
      printer.print(program);

      cout << endl << "Type checking for " << filename << ":" << endl;
      checker.typecheck(program);
      cout << endl << "Running program for " << filename << ":" << endl;
      interpreter.interpret(program);

      cout << "...................." << endl << endl;
      delete program;
    }
  }
}
