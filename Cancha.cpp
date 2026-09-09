#include "Cancha.h"

cancha::cancha(string cod, string deporte, double precio)
    : codigo(cod), tipoDeporte(deporte), precioHora(precio) {
    for (int i = 0; i < NUM_FRANJAS; i++) {
        franjas[i] = 'L';
    }
    cout << "Cancha creada: " << codigo << endl;
}

string cancha::getCodigo() { return codigo; }
string cancha::getTipoDeporte() { return tipoDeporte; }
double cancha::getPrecioHora() { return precioHora; }

char cancha::getEstadoFranja(int pos) {
    if (!franjaValida(pos)) return '?';
    return franjas[pos];
}

void cancha::setPrecioHora(double nuevoPrecio) {
    if (nuevoPrecio > 0) {
        precioHora = nuevoPrecio;
    }
}

bool cancha::franjaValida(int pos) {
    return (pos >= 0 && pos < NUM_FRANJAS);
}

bool cancha::ponerMantenimiento(int pos) {
    if (!franjaValida(pos)) return false;
    if (franjas[pos] == 'O') return false;
    franjas[pos] = 'M';
    return true;
}

bool cancha::quitarMantenimiento(int pos) {
    if (!franjaValida(pos)) return false;
    if (franjas[pos] != 'M') return false;
    franjas[pos] = 'L';
    return true;
}

bool cancha::ocuparFranja(int pos) {
    if (!franjaValida(pos)) return false;
    if (franjas[pos] != 'L') return false;
    franjas[pos] = 'O';
    return true;
}

bool cancha::liberarFranja(int pos) {
    if (!franjaValida(pos)) return false;
    franjas[pos] = 'L';
    return true;
}

string cancha::toString() {
    stringstream s;
    s << "Codigo: " << codigo
      << " | Deporte: " << tipoDeporte
      << " | Precio/hora: " << precioHora;
    return s.str();
}

string cancha::toStringDisponibilidad() {
    stringstream s;
    int horaInicio = 8;
    s << "Disponibilidad de la cancha " << codigo << endl;
    for (int i = 0; i < NUM_FRANJAS; i++) {
        s << horaInicio + i << ":00-" << horaInicio + i + 1
          << ":00 -> [" << i << "] " << franjas[i] << endl;
    }
    return s.str();
}