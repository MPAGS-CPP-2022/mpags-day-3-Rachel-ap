//! Unit Tests for MPAGSCipher processCommandLine interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ProcessCommandLine.hpp"

TEST_CASE("--version works", "[version]")
{
    const std::vector<std::string> args{"./mpags-cipher", "--version"};
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};

    processCommandLine(args, settings);

    REQUIRE(processCommandLine(args, settings));
    REQUIRE(settings.versionRequested);
}


TEST_CASE("--help works" , "[help]")
{
    const std::vector<std::string> args{"./mpags-cipher", "--help"};
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};

    processCommandLine(args, settings);
    
    REQUIRE(processCommandLine(args, settings));
    REQUIRE(settings.helpRequested);
}

TEST_CASE("-h works", "[help]")
{
    const std::vector<std::string> args{"./mpags-cipher", "-h"};
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};

    processCommandLine(args, settings);
    
    REQUIRE(processCommandLine(args, settings));
    REQUIRE(settings.helpRequested);
}

//is there a way to combine the above?

TEST_CASE("-i works", "[input]")
{
    const std::string inputstring{""};
    const std::vector<std::string> args{"./mpags-cipher", "-i", inputstring};

    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};

    processCommandLine(args, settings);
    
    REQUIRE(processCommandLine(args, settings));

    REQUIRE(settings.inputFile == inputstring);
}

TEST_CASE("-o works", "[output]")
{
    const std::string outputstring{""};
    const std::vector<std::string> args{"./mpags-cipher", "-o", outputstring};

    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};

    processCommandLine(args, settings);
    
    REQUIRE(processCommandLine(args, settings));

    REQUIRE(settings.outputFile == outputstring);
}

TEST_CASE("-k works", "[cipherkey]")
{
    const std::string key{""};
    const std::vector<std::string> args{"./mpags-cipher", "-k", key};

    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};

    processCommandLine(args, settings);
    
    REQUIRE(processCommandLine(args, settings));

    REQUIRE(settings.cipherKey == key);
}

TEST_CASE("--encrypt works", "[encrypt]")
{
    const std::vector<std::string> args{"./mpags-cipher", "--encrypt"};

    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};

    processCommandLine(args, settings);
    
    REQUIRE(processCommandLine(args, settings));

    REQUIRE(settings.mode == CipherMode::Encrypt);
}

TEST_CASE("--decrypt works", "[decrypt]")
{
    const std::vector<std::string> args{"./mpags-cipher", "--decrypt"};

    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};

    processCommandLine(args, settings);
    
    REQUIRE(processCommandLine(args, settings));

    REQUIRE(settings.mode == CipherMode::Decrypt);
}

//cant think of any more right now but I'm sure there is some