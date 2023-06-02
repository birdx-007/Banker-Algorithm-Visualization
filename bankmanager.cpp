#include "bankmanager.h"
#include <QDebug>

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
    std::vector<bool> finish(clientNumber,false);
    std::array<int,Constant::ResourceTypeNum> work(dataAccess->available);
    std::vector<int> safeAllocationSequence;
    bool existAllocatableClient;
    int allocatableClientIndex;
    do
    {
        int i,j;
        for(i=0;i<clientNumber;i++)
        {
            existAllocatableClient = true;
            for(j=0;j<Constant::ResourceTypeNum;j++)
            {
                bool condition = finish[i]==false && dataAccess->need[i][j]<=work[j];
                if(!condition)
                {
                    existAllocatableClient = false;
                    break;
                }
            }
            if(existAllocatableClient)
            {
                allocatableClientIndex = i;
                safeAllocationSequence.push_back(i);
                break;
            }
        }
        if(existAllocatableClient)
        {
            for(j=0;j<Constant::ResourceTypeNum;j++)
            {
                work[j]=work[j]+dataAccess->allocation[allocatableClientIndex][j];
            }
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
    QString s = QString("Bank is safe, client sequence:");
    for(int i=0;i<(int)safeAllocationSequence.size();i++)
    {
        s.append(QString(" %1").arg(safeAllocationSequence[i]));
    }
    qDebug()<<s.toStdString().c_str();
    return true;
}

bool BankManager::bankerAlgorithm(const int &i, const RequestData &request)
{
    for(int j=0;j<Constant::ResourceTypeNum;j++)
    {
        if(request.resourceNeed[j]>dataAccess->need[i][j])
        {
            qDebug()<<"Request is larger than client's need!";
            return false;
        }
    }
    for(int j=0;j<Constant::ResourceTypeNum;j++)
    {
        if(request.resourceNeed[j]>dataAccess->available[j])
        {
            qDebug()<<"Bank doesn't have enough resources for the request yet.";
            return false;
        }
    }
    for(int j=0;j<Constant::ResourceTypeNum;j++)
    {
        // try allocation
        dataAccess->available[j]=dataAccess->available[j]-request.resourceNeed[j];
        dataAccess->allocation[i][j]=dataAccess->allocation[i][j]+request.resourceNeed[j];
        dataAccess->need[i][j]=dataAccess->need[i][j]-request.resourceNeed[j];
    }
    bool isSafe = safetyCheck();
    if(!isSafe)
    {
        for(int j=0;j<Constant::ResourceTypeNum;j++)
        {
            // undo allocation
            dataAccess->available[j]=dataAccess->available[j]+request.resourceNeed[j];
            dataAccess->allocation[i][j]=dataAccess->allocation[i][j]-request.resourceNeed[j];
            dataAccess->need[i][j]=dataAccess->need[i][j]+request.resourceNeed[j];
        }
        qDebug()<<"Bank will be unsafe if execute the allocation.";
        return false;
    }
    return true;
}

