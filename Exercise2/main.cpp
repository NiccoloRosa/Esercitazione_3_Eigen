//ESERCIZIO_2

#include <iostream> //includo la libreria standard per input e output
#include "Eigen/Eigen" //includo la libreria Eigen per l'algebra lineare
#include <iomanip> //Includo la libreria per formattare la notazione scientifica dell'output

using namespace std; //posso usare i tipi di std senza specificare sempre std:
using namespace Eigen; //posso usare i tipi di eigen senza specificare sempre Eigen:

void Solution(Matrix2d A, Vector2d b) //Definisco una funzione void in modo che non debba restituire nulla, ma stampi solo gli output che calcola
{
    Vector2d x_ex;
    x_ex << -1.0e+0,-1.0e+00; //vettore soluzione

    VectorXd xP = A.lu().solve(b); //risolvo il sistema Ax=b con la decomposizione PALU
    VectorXd xQ = A.householderQr().solve(b); //risolvo il sistema Ax=b con la decomposizione QR        

    cout << "SOLUZIONE:\n (PALU): xP = [" << scientific << setprecision(16) << xP.transpose() << "]\n (QR): xQ = [" << scientific << setprecision(16) << xQ.transpose() << "]" << endl; //stampo le soluzioni trasponendo i vettori
    cout << "ERRORI RELATIVI:\n (PALU): errP = " << (x_ex-xP).norm()/x_ex.norm() << "\n (QR): errQ = " << (x_ex-xQ).norm()/x_ex.norm() << endl; //stampo l'errore relativo PALU e QR
}

int main()
{
    //CASO 1:
    Matrix2d A1; 
    A1 << 5.547001962252291e-01,-3.770900990025203e-02, 8.320502943378437e-01,-9.992887623566787e-01; //Rimepio la Matrice A con i valori specificati
    Vector2d b1; 
    b1 << -5.169911863249772e-01, 1.672384680188350e-01; //Riempio il vettore b con i valori specificati    
    cout << "CASO 1:" << endl;
    Solution(A1, b1); //Risolvo il sistema con fattorizzazione Palu e QR
    
    //CASO 2:
    Matrix2d A2;
    A2 << 5.547001962252291e-01,-5.540607316466765e-01, 8.320502943378437e-01,-8.324762492991313e-01; //Rimepio la Matrice A con i valori specificati
    Vector2d b2;
    b2 << -6.394645785530173e-04, 4.259549612877223e-04; //Riempio il vettore b con i valori specificati    
    cout << "\nCASO 2:" << endl;
    Solution(A2, b2); //Risolvo il sistema con fattorizzazione Palu e QR
    
    //CASO 3:
    Matrix2d A3;
    A3 << 5.547001962252291e-01,-5.547001955851905e-01, 8.320502943378437e-01, -8.320502947645361e-01; //Rimepio la Matrice A con i valori specificati
    Vector2d b3;
    b3 << -6.400391328043042e-10, 4.266924591433963e-10; //Riempio il vettore b con i valori specificati    
    cout << "\nCASO 3:" << endl;
    Solution(A3, b3); //Risolvo il sistema con fattorizzazione Palu e QR
    
    return 0;
}
