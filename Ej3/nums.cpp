#include "Ej3.hpp"

Numero::Numero(string input_tag): tag(input_tag){
    if(input_tag != "Entero" && input_tag != "Real" && input_tag != "Complejo"){
        throw invalid_argument("Invalid tag provided");
    }
}
