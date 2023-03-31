//
// Created by Youssef Abbas on 29/03/2023.
//

#ifndef PROJECT_SPRINT_2_TERMINAL_H
#define PROJECT_SPRINT_2_TERMINAL_H
#include <stdint.h>
#include "../Card/card.h"
typedef struct ST_terminalData_t
{
    float transAmount;
    float maxTransAmount;
    uint8_t transactionDate[11];
}ST_terminalData_t;

typedef enum EN_terminalError_t
{
    OK, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t;

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData);

EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData);

EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData);

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData);

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData);

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData);

#endif //PROJECT_SPRINT_2_TERMINAL_H
