/*
    В древности для шифрования сообщений использовался такой способ: все буквы в сообщении сдвигались на одно и то же число позиций в алфавите. 
    Число позиций могло быть как положительным, так и отрицательным и являлось параметром шифра. Если для сдвига на данное число позиций алфавита не хватает, 
    то он зацикливается (то есть буква с номером 27 — это снова буква «a», буква с номером 28 — это «b» и так далее).

    Например, слово abracadabra при сдвиге на 10 позиций превратится в klbkmknklbk. Этот простейший шифр называется шифром Цезаря. 
    Регистр букв (заглавные и строчные) менять не нужно. Напишите функцию encrypt_caesar от строки и числа, которая возвращает исходную строку, 
    зашифрованную шифром Цезаря с параметром, равным данному числу. Также напишите функцию decrypt_caesar, выполняющую обратное преобразование. 
    Считаем, что входные строки состоят лишь из английских букв; если там содержатся и другие символы, то их надо игнорировать.

    Пример 1
    The quick brown fox jumps over the lazy dog
    Результат:
    Ymj vznhp gwtbs ktc ozrux tajw ymj qfed itl

    Пример 2
    Lorem ipsum dolor sit amet consectetur adipiscing elit sed do eiusmod tempor incididunt ut labore et dolore magna aliqua Ut enim ad minim veniam quis
    nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore
    eu fugiat nulla pariatur Excepteur sint occaecat cupidatat non proident sunt in culpa qui officia deserunt mollit anim id est laborum
    Результат:
    Knqdl hortl cnknq rhs zlds bnmrdbsdstq zchohrbhmf dkhs rdc cn dhtrlnc sdlonq hmbhchctms ts kzanqd ds cnknqd lzfmz zkhptz Ts dmhl zc lhmhl udmhzl pthr
    mnrsqtc dwdqbhszshnm tkkzlbn kzanqhr mhrh ts zkhptho dw dz bnllncn bnmrdptzs Cthr ztsd hqtqd cnknq hm qdoqdgdmcdqhs hm unktoszsd udkhs drrd bhkktl cnknqd
    dt etfhzs mtkkz ozqhzstq Dwbdosdtq rhms nbbzdbzs btohczszs mnm oqnhcdms rtms hm btkoz pth neehbhz cdrdqtms lnkkhs zmhl hc drs kzanqtl

    Советы и рекомендации
    Уже имея функцию encrypt_caesar, функцию decrypt_caesar можно реализовать в одну строчку.

    Что оценивается
    Корректность работы программы по созданию зашифрованной версии слова или текста.
*/

#include <iostream>
#include <string>
using namespace std;

string encrypt_caesar(string szText, int nKey) {

    // variable for encrypt
    string szCipher;

    //slide of each char by key (except for space and signs)
    //(A-Z 65-90; a-z 97-122)
    for (int nChar = 0; nChar < szText.size(); nChar++) {
        //slide A-Z
        if (szText[nChar] > 64 && szText[nChar] < 91) {
            (szText[nChar] + nKey) > 90 ? szCipher += szText[nChar] + nKey - 26 : ((szText[nChar] + nKey) < 65 ? szCipher += szText[nChar] + nKey + 26 : szCipher += szText[nChar] + nKey);
        }
        //slide a-z
        else if (szText[nChar] > 96 && szText[nChar] < 123) {
            (szText[nChar] + nKey) > 122 ? szCipher += szText[nChar] + nKey - 26 : ((szText[nChar] + nKey) < 97 ? szCipher += szText[nChar] + nKey + 26 : szCipher += szText[nChar] + nKey);
        }
        //except space
        else if (szText[nChar] == ' ') {
            szCipher += ' ';
        }
        //except other
        else {
            szCipher += szText[nChar];
        }
    }
    //return encrypt
    return szCipher;
}

string decrypt_caesar(string szText, int nKey) {
    return encrypt_caesar(encrypt_caesar(szText, nKey), -nKey);
    
}

int main()
{
    //text input
    string szText;
    cout << "input text: ";
    getline(cin, szText);

    //key input
    int nKey = 0;
    cout << "input key: ";
    cin >> nKey;
    if (nKey > 26 || nKey < -26) {
        nKey -= (nKey / 26) * 26;
    }
    cout << "encrypt: "
        << encrypt_caesar(szText, nKey) << endl
        << "decrypt: " 
        << decrypt_caesar(szText, nKey);
}


