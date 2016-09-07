#include "state.h"
void State::SetIsOneTimeEntered(bool _isOneTimeEntered){
    isOneTimeEntered = _isOneTimeEntered;
}

bool State::GetIsOneTimeEntered(){
    return isOneTimeEntered;
}
