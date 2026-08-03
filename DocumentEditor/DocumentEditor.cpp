#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class DocumentElement
{
public:
    virtual string render() = 0;
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
    string render()
    {
        return text;
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
    string render()
    {
        return imagePath;
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
    string getElements(){
        string results;
        for(auto it : elements){
            results += it->render() + " ";
        }
        return results;
    }
};

class Persistence{
    public:
    virtual void save(string str) = 0;
};

class FileSystem : public Persistence{

    void save(string elemnets){
        cout<< elemnets << "saved in File System";
    }
};

class DBSystem : public Persistence
{

    void save(string elemnets)
    {
        cout << elemnets <<"saved in Data Base";
    }
};


class DocumentEditor{
    private:
        Document *doc;
        Persistence *str;
        string renderdocs;

    public:
        DocumentEditor(Document *doc, Persistence *str){
            this->doc = doc;
            this->str = str;
        }
        
        void addText(string text){
            doc->addElement(new TextElement(text));
        }
        void addImage(string path)
        {
            doc->addElement(new ImageElement(path));
        }
        string renderDocumets(){
            if(renderdocs.empty())
                renderdocs = doc->getElements();
            return renderdocs;
        }

        void saveDocuemts(){
            str->save(renderDocumets());
        }
        
};

int main(){
    Document *doc = new Document();
    Persistence *per = new FileSystem();
    DocumentEditor *editor = new DocumentEditor(doc, per);

    editor->addText("hello Shivam");
    editor->addImage("shiva.png");
    cout << editor->renderDocumets();
    cout<<endl;
    editor->saveDocuemts();

}
