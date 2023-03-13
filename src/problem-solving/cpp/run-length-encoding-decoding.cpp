string encode(const string src)
{
  string result;
  for(int i = 1, count = 1; i <= src.size(); i++)
  {
      if( (i== src.size()) || src[i] != src[i-1])
      {
          // Found new character so write the count of previous character
          result += src[i-1] + std::to_string(count);
          count = 1;
      }
      else
      {
          ++count;
      }
  }
  return result;
}

string decode(const string src)
{
    int count = 0;
    string result;
    for(const char c : src)
    {
        if(isdigit(c))
        {
            count = count * 10 + c - '0';
        }
        else // c is a letter of alphabet
        {
            result.append(count,c); // Appends count copies of c to result
            count = 0;
        }
    }
    return result;
}