#include "main.hpp"

void Motor::ligar()
{
    cout << "Motor Ligado!" << endl;
}

void Motor::desligar()
{
    cout << "Motor desligado!" << endl;
}

void Motor::aumentarRpm(int rpm_int)
{
    if (rpm_int < 0)
    {
        cout << "RPM nao pode ser negativo!" << endl;
    }
    else if (rpm_int > 10000) 
    {
        cout << "RPM máximo atingido!" << endl;
    }
    else
    {
        cout << "Aumentando RPM para " << rpm_int << endl;
    }
}

void Motor::diminuirRpm(int rpm_int)
{
    if (rpm_int < 0)
    {
        cout << "RPM nao pode ser negativo!" << endl;
    }
    else if (rpm_int > 10000)
    {
        cout << "RPM nao pode ser maior que 10000!" << endl;
    }
    else
    {
        cout << "Diminuindo RPM para " << rpm_int << endl;
    }
}

Motor motor_class;

void Carro::ligarCarro()
{
    if(!motorLigado_b)
    {
        motor_class.ligar();
        motorLigado_b = true;
    } 
};

void Carro::desligarCarro()
{
    if (motorLigado_b)
    {
        motor_class.desligar();
        motorLigado_b = false;
    }
};

void Carro::aumentarRpmCarro(int rpm_int)
{
    if (!motorLigado_b)
    {
        cout << "O motor precisa estar ligado!" << endl;
        return;
    }

    if(rpmAtual_int + rpm_int > 10000)
    {
        cout << "RPM nao pode ser maior que 10000!" << endl;
        return;
    }

    rpmAtual_int += rpm_int;
    motor_class.aumentarRpm(rpmAtual_int);
    registrosRpm_int.push_back(rpmAtual_int);
};

void Carro::diminuirRpmCarro(int rpm_int)
{
    if (!motorLigado_b)
    {
        cout << "O motor precisa estar ligado!" << endl; 
    }

    if(rpmAtual_int - rpm_int < 0)
    {
        cout << "RPM nao pode ser negativo!" << endl;
        return;
    }

    rpmAtual_int -= rpm_int;
    motor_class.diminuirRpm(rpmAtual_int);
    registrosRpm_int.push_back(rpmAtual_int);
};

void Carro::exibirRegistros()
{
    for (int i = 0; i < registrosRpm_int.size(); i++)
    {
        cout << "Registro " << i + 1 << ": " << registrosRpm_int[i] << " RPM" << endl;
    }
};

int main()
{
    Carro meuCarro;

    meuCarro.ligarCarro();

    meuCarro.aumentarRpmCarro(12000);
    meuCarro.diminuirRpmCarro(13000);
    meuCarro.aumentarRpmCarro(10000);
    meuCarro.diminuirRpmCarro(2000);
    meuCarro.aumentarRpmCarro(8000);
    meuCarro.diminuirRpmCarro(1000); 
    meuCarro.diminuirRpmCarro(4000);
    meuCarro.aumentarRpmCarro(8000);
    meuCarro.diminuirRpmCarro(4000);

    meuCarro.desligarCarro();
    meuCarro.exibirRegistros();

    return 0;
}