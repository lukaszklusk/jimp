//
// Created by kluch on 13.03.18.
//

#include <string>
#include <vector>
#include <algorithm>

std::string XorCypherBreaker(const std::vector<char> &cryptogram, int key_length, const std::vector<std::string> &dictionary){
    std::string key_guess = "";
    std::vector<std::string> tekst;
    tekst.emplace_back("");
    bool found = false;
    int it = 0, it_t = 0;
    char lit;
    key_guess = "aaa";
    while(!found){
        lit = (char)(cryptogram[it] ^ key_guess[it%3]);
        if((lit >= 'a' && lit <= 'z' ) || (lit >= 'A' && lit <= 'Z')){
            tekst[it_t].push_back(lit);
        }else{
            if(lit == ' '){
                tekst.emplace_back("");
                it_t++;
            }
        }
        it++;
        if(it == cryptogram.size()){
            while(!tekst.empty()){
                if(dictionary.end() != std::find(dictionary.begin() , dictionary.end() , tekst.pop_back())){ //nie wiem czemu tu jest zle, kod powinien dzialac
                    found = true;
                }
            }
            if(!found){
                if(key_guess[2] == 'z'){
                    if(key_guess[1] == 'z'){
                        if(key_guess[0] == 'z'){
                            break;
                        }else{
                            key_guess[0] = (char)((int)key_guess[0] + 1);
                        }
                        key_guess[1] = 'a';
                    }else{
                        key_guess[1] = (char)((int)key_guess[1] + 1);
                    }
                    key_guess[2] = 'a';
                }else{
                    key_guess[2] = (char)((int)key_guess[2] + 1);
                }
            }
            it = 0;
            tekst.clear();
            it_t = 0;
        }
    }
    return key_guess;
}