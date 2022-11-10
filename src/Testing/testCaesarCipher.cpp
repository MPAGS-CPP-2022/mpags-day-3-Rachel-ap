//! Unit Tests for MPAGSCipher processCommandLine interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "CaesarCipher.hpp"

TEST_CASE("caesar cipher encrypts", "[ccipher]"){ 
    CaesarCipher caesar(2);
    std::string inputText{"ABCDEF"};

    REQUIRE(caesar.applyCipher(inputText, CipherMode::Encrypt) == "CDEFGH");
}

TEST_CASE("caesar cipher decrypts", "[ccipher]"){ 
    CaesarCipher caesar(2);
    std::string inputText{"ABCDEF"};

    REQUIRE(caesar.applyCipher(inputText, CipherMode::Decrypt) == "YZABCD");
}

// probably more tests to do here i.e if wrong key put in as argument but didn't have time to add this on.

