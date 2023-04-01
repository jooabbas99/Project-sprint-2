//
// Created by Sara Mohamed.
//

#include "card.h"
EN_cardError_t getCardHolderName(ST_cardData_t *cardData){
    printf("Pleas enter cardholder name : \n# Max letters is 24 and min is 20 #\n");
    gets(cardData->cardHolderName);
    int8_t nameSize = strlen(cardData->cardHolderName);
    if(nameSize > 24 || nameSize < 20 || nameSize == NULL)
        return WRONG_NAME;
    return CARD_OK;
}
void getCardHolderNameTest(void){
    ST_cardData_t *cardData;
    printf("tester name: sarah\n");
    printf("function name: get card holder name\n");
    printf("Test case 1\n");
    printf("input data:sarah mohamed salah\n");
    printf("falag : %d \n",getCardHolderName(&cardData));
    printf("Expected result: sarah mohamed salah\n");
    printf("actual result :%c\n",cardData->cardHolderName);
    printf("test case 2\n");
    printf("input data :khaled megahed\n ");
    printf("falag : %d \n",getCardHolderName(&cardData));

    printf("expected result :khaled megahed\n");
    printf("Actual result :%c\n", cardData->cardHolderName);
}

EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData){
    printf("Pleas enter card expiry date : \n# Format MM/YY #\n");
    gets(cardData->cardExpirationDate);
    int8_t dateSize = strlen(cardData->cardExpirationDate);

    if(dateSize != 5 || dateSize == NULL ){
        return WRONG_EXP_DATE;
    }
    // check formatting MM/YY
    regex_t regex;
    int reti;
    reti = regcomp(&regex, "^[0-9]{2}/[0-9]{2}$", REG_EXTENDED);
    reti = regexec(&regex, cardData->cardExpirationDate, 0, NULL, 0);
    regfree(&regex);
    if (reti) {
        return WRONG_EXP_DATE;
    }
    return CARD_OK;
}
void getCardExpiryDateTest(void){
    ST_cardData_t *cardData;
    printf("tester name: sarah\n");
    printf("function name: get card Expiry Date\n");
    printf("Test case 1\n");
    printf("input data:10/2024\n");
    printf("Expected result: 10/2024\n");
    printf("actual result :%c",&cardData);
    printf("test case 2\n");
    printf("input data :11/2023 \n");
    printf("expected result :11/ 2023\n");
    printf("Actual result :%c\n", &cardData);
}
EN_cardError_t getCardPAN(ST_cardData_t *cardData){
    printf("Pleas enter Primary Account Number : \n# 16~19 Numbers #\n");
    gets(cardData->primaryAccountNumber);
    int8_t PANSize = strlen(cardData->primaryAccountNumber);

    if(PANSize > 19 || PANSize < 16 ||PANSize == NULL ){
        return WRONG_PAN;
    }
    // check formatting Numeric
    regex_t regex;
    int reti;
    reti = regcomp(&regex, "^[0-9]+$", REG_EXTENDED);
    reti = regexec(&regex, cardData->primaryAccountNumber, 0, NULL, 0);
    regfree(&regex);
    if (reti) {
        return WRONG_PAN;
    }
    return CARD_OK;

}
void getCardPANTest(void){
    ST_cardData_t *cardData;
    printf("tester name: sarah\n");
    printf("function name: get card pan\n");
    printf("Test case 1\n");
    printf("input data:02215662111\n");
    printf("Expected result: 02215662111\n");
    printf("actual result :%c\n",&cardData);
    printf("test case 2\n");
    printf("input data :5514651511555555555610033302563\n");
    printf("expected result :WRONG_PAN\n");
    printf("Actual result :%c\n", &cardData);

}