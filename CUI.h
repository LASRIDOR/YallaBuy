//
// Created by Nadav Suliman on 9/1/20.
//

#ifndef ECOMMERCE_CUI_H
#define ECOMMERCE_CUI_H

class Manager;

static constexpr int PAGE_WIDTH = 50;

void printSubTitle(const string& title);
void printTitle(const string& title);
void printLine();
int printMainMenu();
int printOperatorsMenu();
void printLogin(Manager &manager, string& username, string& password, const string& type);
void emptyBuffer();

#endif //ECOMMERCE_CUI_H
