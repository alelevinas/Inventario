#ifndef REFERENCIA_H
#define REFERENCIA_H

#include <cairomm/context.h>
#include <glibmm/ustring.h>
#include "Area.h"

/** Clase que sirve para la referencia para los gráficos.
 *  Son un cuadradito con el color del área que refieren y la etiqueta
 *  del dato que generó dicha área. */
class Referencia {
    public:
        Referencia(const Area& referente);
        ~Referencia();

        /*
         * setea el estado del texto negrita/normal
         */
        void setNegrita(bool estado);

        /*
         * Dibuja el cuadradito y la referencia sobre el DrawingArea.
         * Devuelve la posicion del siguiente cuadradito.
         */
        double dibujar(Cairo::RefPtr< Cairo::Context >& ctx, double offset);
    private:
        double color[4];
        Glib::ustring etiqueta;
        static double anchoCuadradito;
        Cairo::FontWeight font;
};

#endif  // REFERENCIA_H
