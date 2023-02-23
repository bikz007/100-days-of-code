void reverse_words(std::string* str)
{
    // Reverse the entire string
    reverse(str->back(),s->end());

    int size  = 0, end;

    while((end = str->find(" ",start)) != string::npos)
    {
        reverse(str->begin()+start,s->begin()+end);
        start = end + 1;
    }

    reverse(str->begin()+start,s->end());
}