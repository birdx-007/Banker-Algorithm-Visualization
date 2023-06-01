#include "bankmanager.h"

BankManager::BankManager()
{

}

void BankManager::setDataAccess(BankData *access)
{
    this->dataAccess = access;
}

bool BankManager::safetyCheck()
{
    const int clientNumber = dataAccess->allocation.size();
    std::vector<bool> finish(false,clientNumber);
    std::array<int,Constant::ResourceTypeNum> work(dataAccess->available);
    bool existAllocatableClient;
    do
    {
        existAllocatableClient = false;
        int i,j;
        for(i=0;i<clientNumber;i++)
        {
            for(j=0;j<Constant::ResourceTypeNum;j++)
            {
                bool condition = finish[i]==false && dataAccess->need[i][j]<=work[j];
                if(condition)
                {
                    existAllocatableClient = true;
                    break;
                }
            }
            if(existAllocatableClient)
            {
                break;
            }
        }
        if(existAllocatableClient)
        {
            work[j]=work[j]+dataAccess->allocation[i][j];
            finish[i]=true;
        }
    }
    while(existAllocatableClient);
    for(int i=0;i<clientNumber;i++)
    {
        if(finish[i]==false)
        {
            return false;
        }
    }
    return true;
}

bool BankManager::bankerAlgorithm(const int &i, const RequestData &request)
{
    for(int j=0;j<Constant::ResourceTypeNum;j++)
    {
        if(request.resourceNeed[j]>dataAccess->need[i][j])
        {
            return false;
        }
        if(request.resourceNeed[j]>dataAccess->available[j])
        {
            return false;
        }
        // try allocation
        dataAccess->available[j]=dataAccess->available[j]-request.resourceNeed[j];
        dataAccess->allocation[i][j]=dataAccess->allocation[i][j]+request.resourceNeed[j];
        dataAccess->need[i][j]=dataAccess->need[i][j]-request.resourceNeed[j];
        if(!safetyCheck())
        {
            // undo allocation
            dataAccess->available[j]=dataAccess->available[j]+request.resourceNeed[j];
            dataAccess->allocation[i][j]=dataAccess->allocation[i][j]-request.resourceNeed[j];
            dataAccess->need[i][j]=dataAccess->need[i][j]+request.resourceNeed[j];
            return false;
        }
    }
    return true;
}

