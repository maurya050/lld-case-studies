#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class DocumentElement
{
public:
    virtual void render() = 0;
    virtual ~DocumentElement() = default;
};

class TextElement : public DocumentElement
{
private:
    string text;

public:
    TextElement(string text)
    {
        this->text = text;
    }
    void render()
    {
        cout << "Text Element :" << text;
    }
};

class ImageElement : public DocumentElement
{
private:
    string imagePath;

public:
    ImageElement(string imagePath)
    {
        this->imagePath = imagePath;
    }
    void render()
    {
        cout << "Image  :" << imagePath;
    }
};

class Document
{
private:
    vector<DocumentElement *> elements;

public:
    void addElement(DocumentElement *el)
    {
        elements.push_back(el);
    }
};