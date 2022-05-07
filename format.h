#ifndef FORMAT_H
#define FORMAT_H


class Format
{
public:
    Format();
    ~Format();

    bool isBold();
    bool isUnderlined();
    bool isItalics();

    void setBold(bool _bold);
    void setUnderlined(bool _underlined);
    void setItalics(bool _italics);

private:
    bool underlined;
    bool bold;
    bool italics;
};

#endif // FORMAT_H
