#ifndef WRAPPER_H
#define WRAPPER_H

#include <memory>
#include <cstdlib>
#include "dylib.hpp" // dylib.hpp is a header file that contains the dylib class that extracts a function from dll

class eventHelper
{
    public:
        std::unique_ptr<dylib> library;
    
        eventHelper(void){};
        ~eventHelper(void){};

        eventHelper& operator=(eventHelper &&other) noexcept
        {
            if (this != &other) {
                this->library = std::move(other.library);
            }
            return *this;
        };

        bool init(void)
        {   
            try 
            {
                this->library = std::make_unique<dylib>("EventManager", dylib::extension);
                return true;
            } 
            catch (const dylib::handle_error &) 
            {
                return false;
            }   
        };

        void sendMessage(const char* msg)
        {                              
            auto func = library->get_function<void(const char*)>("sendMessage");
            
            // pass the arguments to the function
            return func(msg);   

        };

        void updatePlot(int nContrast, double* reflect, int nReflect, double* shiftedData, int nShiftedData, 
                        double* sldProfiles, int nSldProfiles, double* layers, int nLayers, double* ssubs, 
                        double* resample, double* dataPresent, const char* modelType)
        {                              
            auto func = library->get_function<void(int, double*, int, double*, int, 
                                                   double*, int, double*, int, double*, 
                                                   double*, double*, const char*)>("updatePlot");
            
            // pass the arguments to the function
            return func(nContrast, reflect, nReflect, shiftedData, nShiftedData, sldProfiles, nSldProfiles, 
                        layers, nLayers, ssubs, resample, dataPresent, modelType);   

        };
};

#endif
