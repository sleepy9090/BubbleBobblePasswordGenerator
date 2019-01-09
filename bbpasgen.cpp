/**
 ************************************************************************************************************************
 *
 *  @file                   bbpasgen.cpp
 *  @brief                  Bubble Bobble password generator for
 *                          NES version
 *  @copyright              2019 Shawn M. Crawford
 *  @date                   January 8th, 2019
 *
 *  @remark Author:         Shawn M. Crawford
 *
 *  @note                   This is all purposely made verbose.
 *
 ************************************************************************************************************************
 */

/* Includes */
#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;

/**
 ************************************************************************************************************************
 *
 * @brief   Converts number to string of number
 *
 * @param   Number The number to convert
 *
 * @return  The number as a string
 *
 * @note    N/A
 *
 ************************************************************************************************************************
 */
template <typename T>
  std::string NumberToString ( T Number )
  {
     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }

/**
 ************************************************************************************************************************
 *
 * @brief   Encodes password
 *
 * @param   num The number to match to the cypher
 *
 * @return  The letter matched in the cyper or ? if not found
 *
 * @note 
 * Cypher
 * 0 = B
 * 1 = A
 * 2 = I
 * 3 = F
 * 4 = J
 * 5 = C
 * 6 = G
 * 7 = E
 * 8 = D
 * 9 = H
 *
 ************************************************************************************************************************
 */
string encodePassword(int num)
{
    string result = "";

    switch (num)
    {
        case 0:
            result = "B";
            cout << "  Found match: " << result << endl;
            break;
        case 1:
            result = "A";
            cout << "  Found match: " << result << endl;
            break;
        case 2:
            result = "I";
            cout << "  Found match: " << result << endl;
            break;
        case 3:
            result = "F";
            cout << "  Found match: " << result << endl;
            break;
        case 4:
            result = "J";
            cout << "  Found match: " << result << endl;
            break;
        case 5:
            result = "C";
            cout << "  Found match: " << result << endl;
            break;
        case 6:
            result = "G";
            cout << "  Found match: " << result << endl;
            break;
        case 7:
            result = "E";
            cout << "  Found match: " << result << endl;
            break;
        case 8:
            result = "D";
            cout << "  Found match: " << result << endl;
            break;
        case 9:
            result = "H";
            cout << "  Found match: " << result << endl;
            break;
        default:
            result = "?";
            cout << "  Unknown number passed in. Password generation Failed." << endl;
    }
    return result;
}

/**
 ************************************************************************************************************************
 *
 * @brief   Runs the program
 *
 * @param   N/A
 *
 * @return  N/A
 *
 * @note    N/A
 *
 ************************************************************************************************************************
 */
int main (int argc, char *argv[])
{
    int level = 0;
    int superFlag = 0;
    int crystalBallFlag = 0;
    string superFlagString = "";
    string crystalBallFlagString = "";
    string levelBin = "";
    string crystalBallBin = "";
    string checksumBin = "";
    string password = "";
    string data0 = "";
    string data1 = "";
    string data2 = "";
    string data3 = "";
    string data4 = "";
    string tempData = "";
    string data0Bin = "";
    string data1Bin = "";
    string data2Bin = "";
    string data3Bin = "";
    string data4Bin = "";
    string tempDataBin = "";
    string input = "";

    cout << "Bubble Bobble password generator v 1.0" << endl;
    cout << "Coded by: sleepy" << endl;
    cout << "======================================" << endl;
    cout << endl;

    while (true) {
        cout << "Enter level number (0..127): ";
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> level)
        {
            if (level >= 0 && level <= 127)
            {
                break;
            }
        }
        
        cout << "Invalid number, please try again." << endl;
    }

    input = "";
    while (true) {
        cout << "Enter 0 for Regular Bubble Bobble or 1 for Super Bubble Bobble (0..1): ";
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> superFlag)
        {
            if (superFlag >= 0 && superFlag <= 1)
            {
                break;
            }
        }
        
        cout << "Invalid number, please try again." << endl;
    }

    input = "";
    while (true) {
        cout << "Enter for Crystal Ball collected or not collected (0..3): ";
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> crystalBallFlag)
        {
            if (crystalBallFlag >= 0 && crystalBallFlag <= 3)
            {
                break;
            }
        }
        
        cout << "Invalid number, please try again." << endl;
    }

    cout << endl;
    cout << "======================================" << endl;
    cout << "Password data: " << endl;
    cout << "  Level number: " << level << endl;

    levelBin = bitset<8>(level).to_string();
    cout << "  Level number (binary): " << levelBin << endl;
    // ignore first bit
    // pad each string with leading 0
    data0 = string(1, '0') + levelBin.substr(1, 3);
    data1 = string(1, '0') + levelBin.substr(4, 3);
    data2 = string(3, '0') + levelBin.substr(7, 1);

    superFlagString = NumberToString(superFlag);
    // 1 or 0, code only cares if 0 or not 0 in actual game, here it is limited to 0 or 1
    cout << "  Super Bubble Bobble Flag: " << superFlagString << endl;
    crystalBallBin = bitset<2>(crystalBallFlag).to_string();
    cout << "  Crystal Ball two digit Binary: " << crystalBallBin << endl;
    cout << endl;

    data3 = string(1, '0') + superFlagString + crystalBallBin;

    // Get decimal for XORing
    unsigned long data0Dec = bitset<8>(data0).to_ulong();
    unsigned long data1Dec = bitset<8>(data1).to_ulong();

    
    cout << "==============================" << endl;
    cout << "Pre-checksum calculation:" << endl;
    unsigned long data2Dec = bitset<8>(data2).to_ulong();
    cout << "  data2 decimal: " << data2Dec << endl;
    data2Bin = bitset<8>(data2Dec).to_string();
    cout << "  data2 binary: " << data2Bin << endl;
    cout << endl;
    
    cout << "==============================" << endl;
    cout << "Checksum calculation:" << endl;
    data0Bin = bitset<8>(data0Dec).to_string();
    data1Bin = bitset<8>(data1Dec).to_string();

    unsigned long data3Dec = bitset<8>(data3).to_ulong();
    cout << "  Add data0Dec + data1Dec + data2Dec + data3Dec" << endl;
    data3Bin = bitset<8>(data3Dec).to_string();
    cout << "    " << data0Dec << " + " << data1Dec << " + " << data2Dec << " + " << data3Dec << endl;
    cout << "    " << data0Bin << " + " << data1Bin << " + " << data2Bin << " + " << data3Bin << endl;
    unsigned long checksumDec = data0Dec + data1Dec + data2Dec + data3Dec;
    checksumBin = bitset<8>(checksumDec).to_string();
    cout << "  Checksum binary: " << checksumBin << endl;
    // copy from the checksum to the 2 middle bits in data2
    tempData = "0" + checksumBin.substr(3,2) + "0";
    cout << "  Temp Data Binary (add with data 2): " << tempData << endl;
    unsigned long tempDataDec = bitset<8>(tempData).to_ulong();
    cout << "  Temp Data Decimal: " << tempDataDec << endl;
    data2Dec = data2Dec + tempDataDec;

    // copy last three bits from checksum to last three in data4
    data4 = "0" + checksumBin.substr(5, 3);
    unsigned long data4Dec = bitset<8>(data4).to_ulong();
    data4Bin = bitset<8>(data4Dec).to_string();
    cout << endl;

    cout << "==============================" << endl;
    cout << "Pre-XORing:" << endl;

    cout << "  data0 Decimal: " << data0Dec << endl;
    cout << "  data0 Binary: " << data0Bin << endl;

    
    cout << "  data1 Decimal: " << data1Dec << endl;
    cout << "  data1 Binary: " << data1Bin << endl;

    // update data2 binary after checksum changes
    data2Bin = bitset<8>(data2Dec).to_string();
    cout << "  data2 Decimal: " << data2Dec << endl;
    cout << "  data2 Binary: " << data2Bin << endl;

    cout << "  data3 Decimal: " << data3Dec << endl;
    cout << "  data3 Binary: " << data3Bin << endl;
    
    cout << "  data4 Decimal: " << data4Dec << endl;
    cout << "  data4 Binary: " << data4Bin << endl;
    cout << endl;

    cout << "==============================" << endl;
    cout << "Post-XORing:" << endl;

    // first is not XORed
    cout << "  data0 Decimal: " << data0Dec << endl;
    cout << "  data0 Binary: " << data0Bin << endl;

    int d1Result = data0Dec ^ data1Dec;
    cout << "  data1 Decimal: " << d1Result << endl;
    data1Bin = bitset<8>(d1Result).to_string();
    cout << "  data1 Binary: " << data1Bin << endl;

    int d2Result = d1Result ^ data2Dec;
    cout << "  data2 Decimal: " << d2Result << endl;
    data2Bin = bitset<8>(d2Result).to_string();
    cout << "  data2 Binary: " << data2Bin << endl;

    int d3Result = d2Result ^ data3Dec;
    cout << "  data3 Decimal: " << d3Result << endl;
    data3Bin = bitset<8>(d3Result).to_string();
    cout << "  data3 Binary: " << data3Bin << endl;

    int d4Result = d3Result ^ data4Dec;
    cout << "  data4 Decimal: " << d4Result << endl;
    data4Bin = bitset<8>(d4Result).to_string();
    cout << "  data4 Binary: " << data4Bin << endl;
    cout << endl;

    cout << "==============================" << endl;
    cout << "Encoding using Cipher:" << endl;
    password = encodePassword(data0Dec);
    password += encodePassword(d1Result);
    password += encodePassword(d2Result);
    password += encodePassword(d3Result);
    password += encodePassword(d4Result);
    cout << endl;

    cout << "==============================" << endl;
    cout << endl;
    cout << "Generated password: " << password << endl;
    cout << endl;
    cout << "==============================" << endl;

    return(0);
}

