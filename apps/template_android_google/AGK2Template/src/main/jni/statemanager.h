#ifndef STATEMANAGER_H
#define STATEMANAGER_H

class StateManager
{
    public:

        virtual ~StateManager();
        static StateManager* GetInstance();
        static void DestroyInstance();
    protected:

    private:
        static StateManager* m_instance;
        StateManager();
};

#endif // STATEMANAGER_H
