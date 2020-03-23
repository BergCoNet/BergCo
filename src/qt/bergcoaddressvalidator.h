#ifndef BERGCOADDRESSVALIDATOR_H
#define BERGCOADDRESSVALIDATOR_H

#include <QValidator>

/** Base48 entry widget validator.
   Corrects near-miss characters and refuses characters that are no part of base48.
 */
class BergcoAddressValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BergcoAddressValidator(QObject *parent = 0);

    State validate(QString &input, int &pos) const;

    static const int MaxAddressLength = 128;
};

#endif // BERGCOADDRESSVALIDATOR_H
