#ifndef ARTRIX_H
#define ARTRIX_H

//#include "statemachine.h"
//#include "screen.h"
//#include "ButtonWidget.h"
//#include "Managers.h"
//#include "utils.h"

class Artrix
    //: public StateMachine
{
    public:
        Artrix();
        virtual ~Artrix();

        void Begin();
        void Loop();
        void End();

    protected:

    private:

};

/*class ArtrixSanityCheckState
    : public State {

};

class ArtrixJtxCheckState
    : public State {
};

class ArtrixHomeState
    : public State
{
    public:
        void OnOneTimeEnter(const StateMachine* );
        void Update(const StateMachine*, double gameTime);
        ArtrixHomeState();
        ~ArtrixHomeState();
    private:
        Screen* mHomeScreen;
};
*/
#endif // ARTRIX_H
