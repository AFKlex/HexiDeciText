#include<iostream>
#include<string>
#include<vector>
#include <sstream>

class Helper{
    public:
    template<typename t> 
    static void printVector(std::vector<t> input){
        for(int i=0; i<input.size();i++){
            std::cout << input[i] << " "; 
        }
        std::cout << std::endl;
    }
};

class Logic{
    public: 
    static int convertHexStringToInt(std::string value){
        return std::stoi(value, 0, 16);
    }

    public: 
    static int convertDecStringToInt(std::string value){
        return std::stoi(value);
    }

    public: 
    static char convertIntToASCI(int value){
        return char(value);
    }

    public: 
    static std::vector<int> convertDecStringArrayToIntArray(std::vector<std::string> input){
        std::vector<int> result; 
        for(int i=0;i<input.size();i++){
            result.push_back(convertDecStringToInt(input[i]));
        
        }
        return result;
    }   

    public: 
    static std::vector<int> convertHexStringArrayToIntArray(std::vector<std::string> input){
        std::vector<int> result; 
        for(int i=0;i<input.size();i++){
            result.push_back(convertHexStringToInt(input[i]));
            
        }
        return result;
}


};

class StringManipulation{
    public:
    static std::vector<std::string> split(std::string input, char delimeter){

        std::vector<std::string> result; 


        std::stringstream stringArray(input);
        std::string segment;

        while(std::getline(stringArray, segment, delimeter))
        {
            result.push_back(segment);
        }

        return result;

    }



};

int main (int argc, char *argv[]){
    std::string inputString;
    std::vector<std::string> inputArray;
    std::vector<int> valueArray;
    char delemiter= ' ';
    bool hex=false; 
    bool dec=false;

    for (int i=0;i<argc;i++){
        //std::cout << argv[i]<< std::endl; 
        std::string parameter = argv[i];
        //std::cout << argv[i+1] <<"\n" <<std::endl;
        if(parameter =="--help"){
            std::cout << "HexiDeciText: "<<std::endl; 
            std::cout << "Parameter 1: --dec or -d: specify dec input"<<std::endl; 
            std::cout << "Parameter 2: --hex or -h: specify hex input"<<std::endl;
            std::cout << "You can provide a singe value or a Sequence of values seperated by a delimeter"<<std::endl;
            std::cout << "Parameter 3: --delimeter: specify delimeter of the input string (default \" \")"<<std::endl;
            return 0; 
        }

        if((parameter == "--dec"||parameter == "-d") && argv[i+1]!=nullptr){
            dec=true;
            inputString = argv[i+1];
        }

        if((parameter =="--hex"||parameter == "-h") && argv[i+1]!=nullptr){
            inputString = argv[i+1];
            hex=true;
            
        }
        if((parameter =="--delimeter") && argv[i+1]!=nullptr){
            delemiter = (argv[i+1])[0];
            
        }
    }

    if(hex && dec){
        std::cout << "Hex and Dec booth specifed! \nPlease use only -h or -d!" <<std::endl; 
        return 1; 
    }

    inputArray = StringManipulation::split(inputString, delemiter);

    if(hex){
        valueArray = Logic::convertHexStringArrayToIntArray(inputArray);
    }else if(dec){
        valueArray = Logic::convertDecStringArrayToIntArray(inputArray);
    }

    for(int i=0; i< valueArray.size();i++){
        std::cout << Logic::convertIntToASCI(valueArray[i]); 
    }
    std::cout << std::endl;
   
    return 0; 
}