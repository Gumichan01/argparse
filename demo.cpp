#include <iostream>
#include "argparse.hpp"

using namespace std;
using namespace argparse;


int main(int argc, const char** argv) {

  // make a new ArgumentParser
  ArgumentParser parser;

  // add some arguments to search for
  parser.addArgument("--five", 5);
  parser.addArgument("-c", "--cactus", 1);
  parser.addArgument("-v", "--variadic", '+');
  parser.addFinalArgument("final");

  // parse the command-line arguments - throws if invalid format
  parser.parse(argc, argv);

  if (parser.hasParsedArgument("five")) {
      vector<float> five = parser.retrieve<vector<float> >("five");
      cout << "five: " << five << endl;
  }

  if (parser.hasParsedArgument("cactus")) {
      int cactus = parser.retrieve<int>("cactus");
      cout << "cactus: " << cactus << endl;
  }

  if (parser.hasParsedArgument("variadic")) {
      vector<vector<int> > variadic = parser.retrieve<vector<vector<int> > >("variadic");
      cout << "variadic: " << variadic << endl;
  }

  if (parser.hasParsedArgument("final")) {
      string final = parser.retrieve<string>(final);
      cout << "final: " << final << endl;
  }

  const auto& parsedArguments = parser.retrieveParsedArguments();
  for (const ParsedArgument& arg: parsedArguments) {
      std::cout << "Short name: \"" << arg.short_name << "\"; "
                << "Long name: \"" << arg.long_name << "\"; "
                << "Name: \"" << arg.name << "\"\n";
  }

  return 0;
}
