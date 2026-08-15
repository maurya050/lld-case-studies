#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


class ISubscriber{

public:
    virtual void update() = 0;

    virtual ~ISubscriber(){};

};

class IChannel
{
public:
    virtual void subscriber(ISubscriber *subscribers) = 0;
    virtual void unsubscriber(ISubscriber *subscribers) = 0;
    virtual void notifySubscribers() = 0;
    virtual ~IChannel() {};
};


class Channel : public IChannel{


private:
    vector<ISubscriber *> subscribers;
    string name;
    string latestVideo;

public:
    Channel(const string& name){
        this->name = name;

    }

    void subscriber(ISubscriber *subscriber) override{

        if(find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end()){
            subscribers.push_back(subscriber);
        }

    }

    void unsubscriber(ISubscriber *subscriber) override{
        auto it  = find(subscribers.begin(), subscribers.end(), subscriber);

        if(it != subscribers.end())
            subscribers.erase(it);

    }

    void notifySubscribers() override{

        for(ISubscriber *sub : subscribers){
            sub->update();
        }
    }

    void uploadVideo(const string& title){
        latestVideo = title;
        cout << "\n [ "<< name << " uploaded: "<< title << " ] \n";
        notifySubscribers();
    }

    string getVideoData(){
        return "\n Latest Video on channel: " + name + ": " + latestVideo + "\n";
    }
};

class Subscriber : public ISubscriber{

private:
    string name;
    Channel *channel;

public:
    Subscriber(const string& name, Channel* channel){
        this->channel = channel;
        this->name = name;
    }

    void update() override{
        cout << name << ":" <<channel->getVideoData();
    }
};

int main(){

    Channel *channel = new Channel("ShivamFitness");

    Subscriber *sub1 = new Subscriber("Shivam", channel);
    Subscriber *sub2 = new Subscriber("Maurya", channel);

    channel->subscriber(sub1);
    channel->subscriber(sub2);

    channel->uploadVideo("how to get big biceps");

    channel->unsubscriber(sub2);
    channel->uploadVideo("how to calm your mind in 2 min.");

    return 0;
}