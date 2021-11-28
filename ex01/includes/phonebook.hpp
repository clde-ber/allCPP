#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <cstring>
#include <iostream>
#include <cstdlib>

class   profile
{
    private :
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
    public :
        profile(void);
        ~profile(void);
        std::string getFirstName() const;
        void setFirstName(std::string data);
        std::string getLastName() const;
        void setLastName(std::string data);
        std::string getNickName() const;
        void setNickName(std::string data);
        std::string getPhoneNumber() const;
        void setPhoneNumber(std::string data);
        std::string getDarkestSecret() const;
        void setDarkestSecret(std::string data);
        void printContact(std::string str);
};

class	PhoneBook
{
	private :
		int index;
        int _contactNb;
        profile _ind[8];
	public :
        PhoneBook(void);
        ~PhoneBook(void);
		void doPrint(PhoneBook *tmp) const;
        void promptForIndex(void) const;
        int do_add(PhoneBook *ind);
};

#endif
