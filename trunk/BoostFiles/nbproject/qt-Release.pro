TEMPLATE = lib
DESTDIR = dist/Release/GNU-Linux-x86
TARGET = BoostFiles
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += staticlib release 
QT = core gui
SOURCES +=
HEADERS += boost/config/compiler/gcc_xml.hpp boost/preprocessor/iteration/detail/bounds/upper1.hpp boost/config/no_tr1/memory.hpp bits/time.h boost/preprocessor/slot/detail/slot3.hpp boost/preprocessor/list/detail/fold_left.hpp boost/type_traits/remove_cv.hpp boost/preprocessor/arithmetic/add.hpp boost/config/stdlib/roguewave.hpp boost/type_traits/detail/ice_or.hpp boost/preprocessor/repetition/detail/dmc/for.hpp boost/smart_ptr/detail/sp_counted_base_cw_ppc.hpp boost/preprocessor/control/while.hpp boost/type_traits/is_function.hpp boost/config/compiler/digitalmars.hpp boost/format/detail/msvc_disambiguater.hpp boost/preprocessor/array/elem.hpp bits/sigstack.h boost/smart_ptr/detail/spinlock.hpp boost/utility/compare_pointees.hpp boost/smart_ptr/detail/operator_bool.hpp boost/format.hpp boost/type_traits/alignment_of.hpp boost/config/select_platform_config.hpp boost/mpl/if.hpp boost/mpl/aux_/lambda_support.hpp boost/format/format_fwd.hpp sys/time.h boost/format/internals.hpp bits/confname.h stdint.h ctype.h boost/smart_ptr/detail/sp_counted_base_spin.hpp boost/preprocessor/iteration/detail/iter/reverse1.hpp boost/memory_order.hpp boost/preprocessor/repeat.hpp boost/limits.hpp boost/mpl/aux_/preprocessor/sub.hpp boost/config/auto_link.hpp signal.h boost/preprocessor/iteration/detail/bounds/lower1.hpp boost/preprocessor/iteration/detail/bounds/upper5.hpp boost/config/suffix.hpp boost/mpl/aux_/config/adl.hpp gnu/stubs-32.h boost/smart_ptr/detail/spinlock_nt.hpp boost/preprocessor/logical/compl.hpp bits/endian.h boost/mpl/aux_/lambda_arity_param.hpp boost/preprocessor/iteration/detail/bounds/lower4.hpp boost/mpl/aux_/config/workaround.hpp boost/mpl/aux_/static_cast.hpp boost/config/select_stdlib_config.hpp boost/config/compiler/common_edg.hpp boost/format/alt_sstream_impl.hpp boost/preprocessor/list/append.hpp boost/preprocessor/iteration/detail/self.hpp boost/format/detail/workarounds_gcc-2_95.hpp boost/type_traits/is_pointer.hpp boost/optional.hpp boost/smart_ptr/detail/lwm_win32_cs.hpp boost/preprocessor/list/reverse.hpp limits.h boost/format/detail/workarounds_stlport.hpp boost/preprocessor/logical/bitand.hpp sys/select.h boost/preprocessor/detail/is_binary.hpp boost/config/compiler/comeau.hpp boost/config/stdlib/modena.hpp boost/preprocessor/control/iif.hpp boost/checked_delete.hpp endian.h boost/exception/detail/attribute_noreturn.hpp boost/config/abi/borland_suffix.hpp boost/smart_ptr/detail/spinlock_pool.hpp boost/smart_ptr/detail/lwm_pthreads.hpp boost/preprocessor/tuple/to_list.hpp boost/config/warning_disable.hpp boost/format/parsing.hpp boost/preprocessor/iteration/detail/iter/forward4.hpp boost/mpl/aux_/config/lambda.hpp boost/config/platform/qnxnto.hpp boost/type_traits/is_member_pointer.hpp boost/config/compiler/kai.hpp boost/smart_ptr/detail/sp_counted_base_gcc_sparc.hpp boost/mpl/aux_/nttp_decl.hpp bits/wchar.h boost/preprocessor/slot/detail/slot2.hpp boost/preprocessor/iteration/detail/iter/reverse4.hpp boost/config.hpp boost/mpl/int_fwd.hpp boost/config/no_tr1/complex.hpp boost/preprocessor/control/expr_iif.hpp boost/config/platform/irix.hpp boost/mpl/aux_/config/msvc.hpp boost/preprocessor/cat.hpp boost/preprocessor/control/detail/while.hpp inttypes.h sys/ucontext.h boost/mpl/aux_/na.hpp boost/type_traits/is_convertible.hpp boost/smart_ptr/detail/sp_counted_base_gcc_mips.hpp boost/mpl/bool.hpp boost/config/compiler/visualc.hpp boost/mpl/aux_/value_wknd.hpp boost/preprocessor/iteration/detail/bounds/lower3.hpp bits/posix1_lim.h boost/format/format_implementation.hpp boost/type_traits/is_float.hpp boost/preprocessor/iteration/detail/iter/reverse2.hpp boost/smart_ptr/detail/sp_counted_base_gcc_ppc.hpp boost/mpl/int.hpp boost/preprocessor/tuple/rem.hpp boost/config/abi/msvc_suffix.hpp boost/preprocessor/repetition/detail/edg/for.hpp asm-generic/errno.h boost/preprocessor/control/detail/msvc/while.hpp boost/preprocessor/iteration/detail/bounds/upper4.hpp boost/type_traits/is_arithmetic.hpp boost/none_t.hpp boost/mpl/aux_/config/gcc.hpp boost/preprocessor/arithmetic/sub.hpp boost/type_traits/detail/is_function_ptr_helper.hpp boost/smart_ptr/detail/sp_counted_base_gcc_x86.hpp boost/preprocessor/iteration/iterate.hpp boost/smart_ptr/detail/spinlock_pt.hpp boost/detail/workaround.hpp boost/preprocessor/iteration/detail/start.hpp boost/shared_ptr.hpp boost/preprocessor/slot/detail/counter.hpp boost/preprocessor/punctuation/comma.hpp boost/type_traits/is_pod.hpp boost/preprocessor/repetition/enum_params.hpp bits/environments.h boost/config/stdlib/stlport.hpp boost/smart_ptr/detail/sp_counted_base_nt.hpp bits/string2.h unistd.h boost/smart_ptr/detail/sp_counted_base_w32.hpp boost/assert.hpp boost/preprocessor/iteration/detail/rlocal.hpp boost/config/abi_suffix.hpp pthread.h bits/predefs.h boost/detail/limits.hpp boost/smart_ptr/detail/spinlock_sync.hpp boost/config/platform/macos.hpp boost/preprocessor/iteration/detail/iter/forward2.hpp boost/type_traits/remove_bounds.hpp boost/mpl/aux_/preprocessor/def_params_tail.hpp linux/errno.h boost/mpl/aux_/na_fwd.hpp time.h boost/config/stdlib/libcomo.hpp boost/type_traits/is_polymorphic.hpp linux/limits.h boost/type_traits/is_abstract.hpp boost/smart_ptr/detail/atomic_count_win32.hpp boost/type_traits/msvc/remove_bounds.hpp boost/type_traits/intrinsics.hpp boost/smart_ptr/scoped_ptr.hpp boost/mpl/size_t_fwd.hpp boost/mpl/aux_/config/dtp.hpp boost/config/abi/borland_prefix.hpp boost/preprocessor/config/config.hpp bits/xopen_lim.h features.h boost/config/stdlib/vacpp.hpp boost/smart_ptr/detail/spinlock_w32.hpp boost/format/format_class.hpp boost/type_traits/detail/is_mem_fun_pointer_tester.hpp boost/smart_ptr/detail/yield_k.hpp boost/config/platform/linux.hpp boost/smart_ptr/detail/sp_counted_base_gcc_ia64.hpp boost/format/exceptions.hpp boost/type_traits/remove_reference.hpp boost/preprocessor/identity.hpp boost/config/posix_features.hpp boost/preprocessor/iteration/detail/iter/forward1.hpp boost/config/user.hpp boost/type_traits/is_same.hpp boost/preprocessor/iteration/detail/bounds/lower2.hpp boost/type_traits/detail/bool_trait_def.hpp boost/type_traits/detail/wrap.hpp boost/mpl/aux_/config/overload_resolution.hpp boost/type_traits/detail/ice_eq.hpp bits/signum.h boost/scoped_array.hpp boost/scoped_ptr.hpp boost/preprocessor/tuple/elem.hpp boost/preprocessor/iteration/detail/iter/reverse3.hpp boost/non_type.hpp boost/mpl/aux_/preprocessor/params.hpp boost/mpl/integral_c.hpp bits/posix2_lim.h boost/config/compiler/pgi.hpp sys/types.h boost/mpl/aux_/config/intel.hpp xlocale.h boost/preprocessor/repetition/enum_binary_params.hpp boost/format/detail/config_macros.hpp boost/type_traits/msvc/remove_reference.hpp boost/preprocessor/array/size.hpp boost/config/compiler/sunpro_cc.hpp boost/preprocessor/list/detail/edg/fold_left.hpp boost/preprocessor/control/if.hpp boost/type_traits/detail/is_mem_fun_pointer_impl.hpp bits/string.h boost/format/detail/compat_workarounds.hpp boost/mpl/aux_/na_spec.hpp boost/config/platform/cygwin.hpp boost/config/compiler/compaq_cxx.hpp boost/preprocessor/iteration/detail/iter/forward5.hpp boost/preprocessor/iteration/detail/local.hpp boost/preprocessor/comma_if.hpp sched.h boost/preprocessor/list/adt.hpp boost/config/select_compiler_config.hpp boost/preprocessor/punctuation/comma_if.hpp asm-generic/errno-base.h boost/mpl/aux_/config/arrays.hpp boost/type_traits/detail/yes_no_type.hpp gnu/stubs.h boost/preprocessor/slot/detail/def.hpp bits/sigaction.h getopt.h boost/mpl/not.hpp boost/preprocessor/facilities/empty.hpp boost/type_traits/has_trivial_copy.hpp boost/type_traits/detail/false_result.hpp boost/preprocessor/list/for_each_i.hpp boost/type_traits/is_class.hpp bits/string3.h boost/config/platform/win32.hpp boost/mpl/aux_/nested_type_wknd.hpp boost/type_traits/detail/size_t_trait_undef.hpp bits/waitstatus.h sys/signal.h boost/config/platform/aix.hpp boost/mpl/aux_/config/static_constant.hpp boost/smart_ptr/detail/lightweight_mutex.hpp string.h boost/preprocessor/repetition/detail/for.hpp bits/setjmp.h boost/type_traits/is_array.hpp errno.h stdlib.h boost/preprocessor/control/detail/edg/while.hpp boost/preprocessor/slot/detail/slot5.hpp boost/config/platform/hpux.hpp boost/mpl/aux_/integral_wrapper.hpp boost/config/compiler/sgi_mipspro.hpp boost/type_traits/integral_constant.hpp boost/format/free_funcs.hpp boost/smart_ptr/detail/atomic_count_sync.hpp boost/mpl/void.hpp boost/mpl/lambda_fwd.hpp boost/mpl/aux_/adl_barrier.hpp boost/preprocessor/array/data.hpp boost/preprocessor/detail/check.hpp boost/mpl/bool_fwd.hpp boost/mpl/aux_/preprocessor/enum.hpp boost/type_traits/add_reference.hpp bits/stdio_lim.h boost/smart_ptr/scoped_array.hpp boost/format/alt_sstream.hpp boost/none.hpp boost/optional/optional_fwd.hpp boost/config/compiler/greenhills.hpp boost/type_traits/msvc/remove_cv.hpp boost/optional/optional.hpp boost/preprocessor/repetition/repeat_from_to.hpp boost/preprocessor/slot/slot.hpp boost/type_traits/type_with_alignment.hpp bits/select.h sys/cdefs.h boost/config/platform/bsd.hpp boost/format/feed_args.hpp boost/preprocessor/iteration/detail/iter/forward3.hpp boost/preprocessor/slot/detail/slot1.hpp boost/type_traits/is_member_function_pointer.hpp boost/mpl/aux_/config/eti.hpp boost/config/stdlib/msl.hpp boost/mpl/void_fwd.hpp boost/exception/exception.hpp boost/type_traits/is_union.hpp bits/unistd.h boost/preprocessor/empty.hpp boost/mpl/aux_/config/ctps.hpp bits/stdlib.h boost/preprocessor/logical/and.hpp boost/type_traits/config.hpp boost/type_traits/has_nothrow_copy.hpp bits/local_lim.h boost/config/compiler/metrowerks.hpp boost/type_traits/detail/is_function_ptr_tester.hpp boost/detail/sp_typeinfo.hpp boost/preprocessor/logical/bool.hpp boost/preprocessor/debug/error.hpp boost/preprocessor/iteration/local.hpp boost/preprocessor/arithmetic/inc.hpp boost/config/stdlib/libstdcpp3.hpp boost/type_traits/detail/template_arity_spec.hpp boost/preprocessor/tuple/eat.hpp boost/preprocessor/detail/auto_rec.hpp boost/preprocessor/iteration/detail/bounds/upper3.hpp boost/detail/endian.hpp bits/wordsize.h boost/current_function.hpp boost/format/internals_fwd.hpp boost/config/compiler/hp_acc.hpp boost/type_traits/is_reference.hpp boost/preprocessor/list/detail/dmc/fold_left.hpp boost/mpl/aux_/config/nttp.hpp boost/config/compiler/mpw.hpp boost/config/compiler/intel.hpp boost/config/compiler/borland.hpp bits/sched.h boost/preprocessor/repetition/for.hpp bits/waitflags.h boost/config/stdlib/sgi.hpp boost/type.hpp alloca.h boost/smart_ptr/detail/sp_convertible.hpp boost/config/abi_prefix.hpp boost/smart_ptr/detail/atomic_count_pthreads.hpp bits/types.h bits/stdlib-ldbl.h boost/preprocessor/iteration/detail/iter/reverse5.hpp boost/type_traits/detail/type_trait_def.hpp boost/smart_ptr/detail/quick_allocator.hpp boost/preprocessor/arithmetic/dec.hpp boost/smart_ptr/detail/shared_ptr_nmt.hpp boost/type_traits/is_volatile.hpp boost/static_assert.hpp boost/config/platform/beos.hpp boost/preprocessor/control/detail/dmc/while.hpp boost/config/no_tr1/cmath.hpp boost/config/platform/vxworks.hpp boost/smart_ptr/detail/sp_counted_base_pt.hpp boost/smart_ptr/detail/sp_counted_base_acc_ia64.hpp bits/sigcontext.h boost/utility/base_from_member.hpp bits/errno.h boost/format/detail/unset_macros.hpp boost/type_traits/detail/cv_traits_impl.hpp boost/config/platform/solaris.hpp boost/config/compiler/vacpp.hpp boost/preprocessor/list/fold_left.hpp bits/sigset.h boost/smart_ptr/detail/atomic_count.hpp boost/preprocessor/list/fold_right.hpp bits/typesizes.h boost/type_traits/detail/ice_and.hpp boost/preprocessor/iteration/detail/finish.hpp bits/byteswap.h bits/posix_opt.h boost/mpl/integral_c_tag.hpp boost/type_traits/broken_compiler_spec.hpp boost/type_traits/is_const.hpp boost/mpl/integral_c_fwd.hpp boost/mpl/aux_/arity.hpp boost/smart_ptr/detail/atomic_count_gcc.hpp boost/type_traits/detail/ice_not.hpp boost/format/group.hpp boost/smart_ptr/detail/lwm_nop.hpp boost/mpl/aux_/preprocessor/filter_params.hpp boost/preprocessor/iteration/detail/bounds/upper2.hpp boost/config/compiler/codegear.hpp boost/detail/interlocked.hpp boost/preprocessor/repetition/detail/msvc/for.hpp boost/preprocessor/enum_params.hpp boost/smart_ptr/detail/sp_counted_base_sync.hpp boost/preprocessor/detail/dmc/auto_rec.hpp boost/config/no_tr1/functional.hpp boost/mpl/aux_/yes_no.hpp boost/type_traits/is_integral.hpp bits/siginfo.h boost/smart_ptr/detail/sp_counted_impl.hpp boost/smart_ptr/detail/sp_has_sync.hpp boost/mpl/aux_/template_arity_fwd.hpp boost/type_traits/is_scalar.hpp sys/sysmacros.h boost/preprocessor/slot/detail/slot4.hpp boost/throw_exception.hpp boost/mpl/aux_/config/preprocessor.hpp boost/preprocessor/inc.hpp boost/type_traits/msvc/typeof.hpp boost/preprocessor/iteration/self.hpp boost/config/stdlib/dinkumware.hpp boost/mpl/aux_/preprocessor/tuple.hpp boost/type_traits/is_enum.hpp boost/config/compiler/gcc.hpp boost/smart_ptr/detail/atomic_count_gcc_x86.hpp boost/mpl/limits/arity.hpp boost/preprocessor/iteration/detail/bounds/lower5.hpp boost/preprocessor/facilities/identity.hpp boost/mpl/aux_/config/integral.hpp boost/detail/reference_content.hpp boost/type_traits/detail/type_trait_undef.hpp boost/smart_ptr/detail/spinlock_gcc_arm.hpp boost/preprocessor/list/transform.hpp bits/pthreadtypes.h boost/smart_ptr/detail/sp_counted_base.hpp boost/mpl/size_t.hpp boost/type_traits/detail/bool_trait_undef.hpp boost/preprocessor/repetition/repeat.hpp boost/config/no_tr1/utility.hpp boost/smart_ptr/bad_weak_ptr.hpp boost/type_traits/ice.hpp bits/sigthread.h boost/smart_ptr/shared_ptr.hpp assert.h boost/config/requires_threads.hpp boost/preprocessor/list/detail/edg/fold_right.hpp boost/mpl/aux_/config/ttp.hpp boost/type_traits/detail/size_t_trait_def.hpp boost/version.hpp boost/preprocessor/list/detail/fold_right.hpp boost/config/platform/amigaos.hpp asm/errno.h boost/type_traits/is_void.hpp boost/config/abi/msvc_prefix.hpp boost/preprocessor/slot/detail/shared.hpp boost/preprocessor/iterate.hpp boost/smart_ptr/detail/shared_count.hpp
FORMS +=
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
