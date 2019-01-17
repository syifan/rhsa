#include <cstdlib>
#include <cstdio>
#include "include/hsa.h"
#include "src/client/client.h"
#include "src/request/request.h"
#include "src/proto/request.pb.h"

extern "C" {
/*
hsa_status_t hsa_ext_program_create(
    hsa_machine_model_t machine_model,
    hsa_profile_t profile,
    hsa_default_float_rounding_mode_t default_float_rounding_mode,
    const char *options,
    hsa_ext_program_t *program) {
    return HSA_STATUS_SUCCESS;
}

hsa_status_t hsa_ext_program_add_module(
    hsa_ext_program_t program,
    hsa_ext_module_t module) {
    return HSA_STATUS_SUCCESS;
}

hsa_status_t hsa_ext_program_finalize(
    hsa_ext_program_t program,
    hsa_isa_t isa,
    int32_t call_convention,
    hsa_ext_control_directives_t control_directives,
    const char *options,
    hsa_code_object_type_t code_object_type,
    hsa_code_object_t *code_object) {
    printf("%i \n", (int) program.handle);
    printf("%i \n", (int) isa.handle);
    printf("%i \n", call_convention);
    printf("%s \n", options);
    return HSA_STATUS_SUCCESS;
}

hsa_status_t hsa_ext_program_destroy(hsa_ext_program_t program) {
    return HSA_STATUS_SUCCESS;
}
*/

hsa_status_t hsa_executable_create(hsa_profile_t profile,
                                   hsa_executable_state_t  executable_state,
                                   const char *options,
                                   hsa_executable_t *executable) {
    
  using namespace rhsa;

  auto &client = Client::GetInstance();
  auto request_factory = client.request_factory.get();

  auto msg = new CreateExecutable();

  msg->set_profile((CreateExecutable_Profile)profile);
  msg->set_executablestate((CreateExecutable_ExecutableState)executable_state);
  msg->set_options(options);

  auto query_req = request_factory->BuildProgramRequest(msg, (RequestFactory::ProgramCommand)0);
  client.conn->Send(query_req.get());

  // placeholder
  return HSA_STATUS_SUCCESS;
}
}
