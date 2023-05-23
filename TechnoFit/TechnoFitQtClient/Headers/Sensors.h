// class ISensor
// {
// public:
//     virtual bool is_graph() = 0;
//     virtual bool is_metric() = 0;
//     virtual float get_param() = 0;
//     virtual void set_param(float param) = 0;
// };

// class PulseSensor : public ISensor
// {
// public:
//     bool is_graph() override
//     {
//         return true;
//     }
//     bool is_metric() override
//     {
//         return true;
//     }
//     void set_param(float param) override
//     {
//         this->pulse = param;
//     }
//     float get_param() override
//     {
//         return this->pulse;
//     }
// private:
//     float pulse;
// };

// class O2Sensor : public ISensor
// {
// public:
//     bool is_graph() override
//     {
//         return true;
//     }
//     bool is_metric() override
//     {
//         return true;
//     }
//     void set_param(float param) override
//     {
//         this->O2 = param;
//     }
//     float get_param() override
//     {
//         return this->O2;
//     }
// private:
//     float O2;
// };

// class TempratureSensor : public ISensor
// {
// public:
//     bool is_graph() override
//     {
//         return true;
//     }
//     bool is_metric() override
//     {
//         return true;
//     }
//     void set_param(float param) override
//     {
//         this->temprature = param;
//     }
//     float get_param() override
//     {
//         return this->temprature;
//     }
// private:
//     float temprature;
// };

// class ECGSensor : public ISensor
// {
// public:
//     bool is_graph() override
//     {
//         return true;
//     }
//     bool is_metric() override
//     {
//         return false;
//     }
//     void set_param(float param) override
//     {
//         this->ECG = param;
//     }
//     float get_param() override
//     {
//         return this->ECG;
//     }
// private:
//     float ECG;
// };

// class BloodPressureSensor : public ISensor
// {
// public:
//     bool is_graph() override
//     {
//         return false;
//     }
//     bool is_metric() override
//     {
//         return true;
//     }
//     void set_param(float param) override
//     {
//         this->BloodPressure = param;
//     }
//     float get_param() override
//     { 
//         return this->BloodPressure;
//     }
// private:
//     float BloodPressure;
// };