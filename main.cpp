// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 3
// Program: CS213-2018-A11-T3
// Purpose: Operation on long int
// Author:  Nouran Qassem & Nehal Akram
// Date:    21 September  2018
// Version: 1.0

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BigDecimalInt
{
    vector <int> vec ;
public:
    BigDecimalInt () // default constructor to set size for vector
    {
        vec.resize(5) ;
        for (int i = 0 ; i < vec.size() ; i++ )
        {
            vec[i] = 0 ;
        }
    }
    void setVec (vector <int> v) // set values for vector
    {
        vec = v ;
    }
    vector<int> getVector () // get values from vector
    {
        return vec ;
    }
    BigDecimalInt (int decInt)  // parameterized constructor to change int to string and save 'em in vector
    {
        vector<int> v ;

        string temp ;
        int x, y,z, c= 1;

        for ( int i = 0 ; i < c ; i++)
        {
            y = decInt % 10 ;
            decInt = decInt / 10 ;
            temp += char(y) + '0' ;
            if (decInt == 0 )
            {
                break ;
            }
            c++ ;
        }
        for (int i = 0 ; i < temp.length() ; i++)
        {
            x = temp[i] - 48  ;
            v.push_back(x) ;
        }
        for (int i = (v.size()-1) ; i > -1 ; i--)
        {
            vec.push_back(v[i]) ;
        }

    }
    BigDecimalInt (string decStr) // parameterized constructor keep data in vector
    {
        vector<int> v ;
        int x ;
        for (int i = 0 ; i < decStr.length() ; i++)
        {
            x = decStr[i] - 48  ;
            v.push_back(x) ;

        }
        vec = v ;
    }
    BigDecimalInt operator+ (BigDecimalInt anotherDec) // sum two objects
    {
        BigDecimalInt b1, b2;

        int a, b, c =0, i, z=0 ;

        if (vec.size() > anotherDec.vec.size() )
        {
            b1.vec = vec ;
            b2.vec = anotherDec.vec ;

            z = (vec.size()) - (anotherDec.vec.size()) ;

            b2.vec.clear() ;
            for (int i = 0 ; i < z ; i ++)
            {
                b2.vec.push_back(0) ;
            }

            for (int i = 0 ; i < anotherDec.vec.size() ; i++)
            {
                b2.vec.push_back(anotherDec.vec[i]) ;
            }
            for (int i = 0 ; i < anotherDec.vec.size() ; i++)
            {
                b2.vec[i] ;
            }
            for (i = vec.size()-1  ; i > -1 ; i-- )
            {
                a = vec[i] + b2.vec[i] + c ;
                if (a > 9)
                {
                    b = a - 10 ;
                    c = 1 ;
                }
                else
                {
                    b = a ;
                    c = 0 ;
                }
                b1.vec[i] = b ;
                if (i==0)
                {
                    b1.vec[i] = a ;
                }
            }
        }

        if (vec.size() < anotherDec.vec.size() )
        {
            b1.vec = anotherDec.vec ;
            b2.vec = vec ;

            z = (anotherDec.vec.size()) - (vec.size())  ;

            b2.vec.clear() ;
            for (int i = 0 ; i < z ; i ++)
            {
                b2.vec.push_back(0) ;
            }

            for (int i = 0 ; i < vec.size() ; i++)
            {
                b2.vec.push_back(vec[i]) ;
            }
            for (i = anotherDec.vec.size()-1  ; i > -1 ; i-- )
            {
                a = anotherDec.vec[i] + b2.vec[i] + c ;
                if (a > 9)
                {
                    b = a - 10 ;
                    c = 1 ;
                }
                else
                {
                    b = a ;
                    c = 0 ;
                }
                b1.vec[i] = b ;
                if (i==0)
                {
                    b1.vec[i] = a ;
                }
            }

        }

        if (vec.size() == anotherDec.vec.size() )
        {
            b1.vec = vec ;

            for (i = vec.size()-1  ; i > -1 ; i-- )
            {
                a = vec[i] + anotherDec.vec[i] + c ;
                if (a > 9)
                {
                    b = a - 10 ;
                    c = 1 ;
                }
                else
                {
                    b = a ;
                    c = 0 ;
                }
                b1.vec[i] = b ;
                if (i==0)
                {
                    b1.vec[i] = a ;
                }
            }
        }

        return b1 ;
    }
    BigDecimalInt operator- (BigDecimalInt anotherDec) // subtract two objects
    {
        BigDecimalInt b1, b2;

        int m=0, n=0, j, c = 0 ;

        if (vec.size() > anotherDec.vec.size() )
        {
            b1.vec = vec ;
            b2.vec = anotherDec.vec ;

            m = (vec.size()) - (anotherDec.vec.size()) ;

            b2.vec.clear() ;

            for (int i = 0 ; i < m ; i++)
            {
                b2.vec.push_back(0) ;
            }
            for (int i = 0 ; i < anotherDec.vec.size() ; i++)
            {
                b2.vec.push_back(anotherDec.vec[i]) ;
            }

            for (int i = vec.size()-1  ; i > -1 ; i-- )
            {
                if (b2.vec[i] > vec[i])
                {
                    n = (vec[i] + 10) - b2.vec[i] ;
                    vec[--i]-- ;
                    i++ ;
                }
                else
                {
                    n = vec[i] - b2.vec[i] ;
                }
                b1.vec[i] = n ;
            }
        }
        if (anotherDec.vec.size() > vec.size())
        {
            b1.vec = anotherDec.vec ;
            b2.vec = vec ;

            m = (anotherDec.vec.size()) - (vec.size())  ;

            b2.vec.clear() ;

            for (int i = 0 ; i < m ; i++)
            {
                b2.vec.push_back(0) ;
            }
            for (int i = 0 ; i < vec.size() ; i++)
            {
                b2.vec.push_back(vec[i]) ;
            }

            anotherDec.vec.swap(b2.vec) ;

            for (int i = b2.vec.size()-1  ; i > -1 ; i-- )
            {
                if (b2.vec[i] < anotherDec.vec[i])
                {
                    n = (b2.vec[i] + 10) - anotherDec.vec[i] ;
                    b2.vec[--i]-- ;
                    i++ ;
                }
                else
                {
                    n = b2.vec[i] - anotherDec.vec[i] ;
                }
                b1.vec[i] = n ;
            }
            for (int i = 0 ; i < b1.vec.size() - 1 ; i++ )
            {
                if (b1.vec[i] == 0)
                {
                    b1.vec.erase(b1.vec.begin()+0, b1.vec.begin()+1 ) ;
                }
                else
                {
                    break ;
                }
            }

            b1.vec[0] *= -1 ;
        }
        if (anotherDec.vec.size() == vec.size())
        {
            b1.vec = vec ;
            int x ;

            for (int i = 0 ; i < vec.size()-1 ; i++)
            {
                if (vec[i] > anotherDec.vec[i])
                {
                    x = 1 ;
                    break ;
                }
                if (vec[i] < anotherDec.vec[i])
                {
                    x = 2 ;
                    break ;
                }
            }
            if (x == 1)
            {
                for (int i = vec.size()-1  ; i > -1 ; i-- )
                {
                    if (vec[i] < anotherDec.vec[i])
                    {
                        n = (vec[i] + 10) - anotherDec.vec[i] ;
                        vec[--i]-- ;
                        i++ ;
                    }
                    else
                    {
                        n = vec[i] - anotherDec.vec[i] ;
                    }
                    b1.vec[i] = n ;
                }
            }
            if(x==2)
            {
                for (int i = vec.size()-1  ; i > -1 ; i-- )
                {
                    if (vec[i] > anotherDec.vec[i])
                    {
                        n = (anotherDec.vec[i] + 10) - vec[i] ;
                        anotherDec.vec[--i]-- ;
                        i++ ;
                    }
                    else
                    {
                        n = anotherDec.vec[i] - vec[i]  ;
                    }
                    b1.vec[i] = n ;
                }
                for (int i = 0 ; i < b1.vec.size() - 1 ; i++ )
                {
                    if (b1.vec[i] == 0)
                    {
                        b1.vec.erase(b1.vec.begin()+0, b1.vec.begin()+1 ) ;
                    }
                    else
                    {
                        break ;
                    }
                }
                b1.vec[0]*= -1 ;
            }
        }
        return b1 ;
    }
    friend ostream& operator<< (ostream& out, BigDecimalInt b) ;
};

ostream& operator<< (ostream& out, BigDecimalInt b) // to output directly from the object
{
    for (int i = 0 ; i < b.vec.size() ; i++)
    {
        out << b.vec[i] ;
    }
    return out ;
}
int main()
{
    string x, y ;
    int z ;

    cout << " First number  = " ;
    cin >> x;
    BigDecimalInt b(x) ;

    cout << " Second number = " ;
    cin >> y ;
    BigDecimalInt b1(y) ;

    cout << " Operator+ = " << b + b1 << endl ;
    cout << "Operator- = " << b - b1 << endl ;

    cout << " enter an integer number: " ;
    cin >> z ;

    BigDecimalInt b2 (z) ;

    cout << " Operator+ = " << b1 + b2 << endl ;
    cout << "Operator- = " << b1 - b2 << endl ;


}
