//
// Created by kluch on 20.03.18.
//

#include <utility>
#include <string>
#include <array>
#include <memory>
#include "TinyUrl.h"


namespace tinyurl {

    std::unique_ptr<TinyUrlCodec> Init(){
        std::unique_ptr<TinyUrlCodec> codec = std::make_unique<TinyUrlCodec>();
        return codec;
    }
    void NextHash(std::array<char, 6> *state) {
        if ((*state).empty())(*state).fill('0');
        if ((*state)[5] == '9') {
            (*state)[5] = 'A';
        } else {
            if ((*state)[5] == 'Z') {
                (*state)[5] = 'a';
            } else {
                if ((*state)[5] == 'z') {
                    (*state)[5] = '0';
                    if ((*state)[4] == '9') {
                        (*state)[4] = 'A';
                    } else {
                        if ((*state)[4] == 'Z') {
                            (*state)[4] = 'a';
                        } else {
                            if ((*state)[4] == 'z') {
                                (*state)[4] = '0';
                                if ((*state)[3] == '9') {
                                    (*state)[3] = 'A';
                                } else {
                                    if ((*state)[3] == 'Z') {
                                        (*state)[3] = 'a';
                                    } else {
                                        if ((*state)[3] == 'z') {
                                            (*state)[3] = '0';
                                            if ((*state)[2] == '9') {
                                                (*state)[2] = 'A';
                                            } else {
                                                if ((*state)[2] == 'Z') {
                                                    (*state)[2] = 'a';
                                                } else {
                                                    if ((*state)[2] == 'z') {
                                                        (*state)[2] = '0';
                                                        if ((*state)[1] == '9') {
                                                            (*state)[1] = 'A';
                                                        } else {
                                                            if ((*state)[1] == 'Z') {
                                                                (*state)[1] = 'a';
                                                            } else {
                                                                if ((*state)[1] == 'z') {
                                                                    (*state)[1] = '0';
                                                                    if ((*state)[0] == '9') {
                                                                        (*state)[0] = 'A';
                                                                    } else {
                                                                        if ((*state)[0] == 'Z') {
                                                                            (*state)[0] = 'a';
                                                                        } else {
                                                                            if ((*state)[0] == 'z') {
                                                                                (*state)[0] = '0';
                                                                            } else {
                                                                                (*state)[0] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                } else {
                                                                    (*state)[1] += 1;
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        (*state)[2] += 1;
                                                    }
                                                }
                                            }
                                        } else {
                                            (*state)[3] += 1;
                                        }
                                    }
                                }
                            } else {
                                (*state)[4] += 1;
                            }
                        }
                    }
                } else {
                    (*state)[5] += 1;
                }
            }
        }
    }
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec){
        std::string wyn = "";
        (*codec)->url = url;
        NextHash(&((*codec)->state));
        for(int i=0;i<6;++i){
            wyn = wyn + (*codec)->state[i];
        }
        (*codec)->hash = wyn;
        return wyn;
    }
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash){
        return codec->url;
    }
}