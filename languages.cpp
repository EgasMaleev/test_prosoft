#include <iostream>
#include <vector>
#include <string>


class CodeGenerator
{
public:
    std::vector<std::string> languages = { "JAVA", "C_PLUS_PLUS", "PHP" };

    CodeGenerator(std::string _lang)
    {
        lang = _lang;
    }

    std::string generateCode()
    {
        for (int i = 0; i != languages.size(); ++i)
        {
            if (this->lang == languages[i])
                return languages[i] + " code" + "\n";
        }

        throw new std::logic_error("Bad language");
    }

    std::string someCodeRelatedThing() // used in generateCode()
    {
        for (int i = 0; i != languages.size(); ++i)
        {
            if (this->lang == languages[i])
                return languages[i] + " stuff" + "\n";
        }
        throw new std::logic_error("Bad language");
    }

    std::string add_lang() // добавялем нужный нам язык
    {
        languages.push_back(this->lang);
        return "language " + this->lang + " created \n";
    }
private:
    std::string lang;
};
