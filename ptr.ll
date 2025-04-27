; ModuleID = 'ptr.cpp'
source_filename = "ptr.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%"class.std::ios_base::Init" = type { i8 }
%"class.std::basic_ostream" = type { ptr, %"class.std::basic_ios" }
%"class.std::basic_ios" = type { %"class.std::ios_base", ptr, i8, i8, ptr, ptr, ptr, ptr }
%"class.std::ios_base" = type { ptr, i64, i64, i32, i32, i32, ptr, %"struct.std::ios_base::_Words", [8 x %"struct.std::ios_base::_Words"], i32, ptr, %"class.std::locale" }
%"struct.std::ios_base::_Words" = type { ptr, i64 }
%"class.std::locale" = type { ptr }
%struct.__va_list_tag = type { i32, i32, ptr, ptr }
%class.Pointer = type { ptr, i64 }

$_Z8make_ptrIiE7PointerIT_Em = comdat any

$_ZN7PointerIiE5writeEi = comdat any

$_ZN7PointerIiEdeEv = comdat any

$_ZN7PointerIiE7deallocEv = comdat any

$_ZN7PointerIiE5allocEm = comdat any

$_ZN7PointerIiEplEj = comdat any

$_ZN7PointerIiE4readEv = comdat any

$_ZN7PointerIiEC2Ev = comdat any

$_ZN7PointerIiE13error_on_nullEv = comdat any

$_ZN7PointerIiEC2EPim = comdat any

@_ZStL8__ioinit = internal global %"class.std::ios_base::Init" zeroinitializer, align 1
@__dso_handle = external hidden global i8
@.str = private unnamed_addr constant [19 x i8] c"\1B[34m[DEBUG]: \1B[0m\00", align 1
@.str.1 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@_ZSt4cout = external global %"class.std::basic_ostream", align 8
@.str.2 = private unnamed_addr constant [2 x i8] c" \00", align 1
@.str.3 = private unnamed_addr constant [27 x i8] c"Curr size: %d, Pointer: %p\00", align 1
@.str.4 = private unnamed_addr constant [19 x i8] c"\1B[91m[ERROR]:\1B[0m \00", align 1
@.str.5 = private unnamed_addr constant [24 x i8] c"Null pointer exception\0A\00", align 1
@.str.6 = private unnamed_addr constant [42 x i8] c"Prev Size: %d, Curr size: %d, Pointer: %p\00", align 1
@.str.7 = private unnamed_addr constant [22 x i8] c"Address: %p, size: %d\00", align 1
@.str.8 = private unnamed_addr constant [47 x i8] c"Cannot excess access outside scope of pointer\0A\00", align 1
@llvm.global_ctors = appending global [1 x { i32, ptr, ptr }] [{ i32, ptr, ptr } { i32 65535, ptr @_GLOBAL__sub_I_ptr.cpp, ptr null }]

; Function Attrs: noinline uwtable
define internal void @__cxx_global_var_init() #0 section ".text.startup" {
  call void @_ZNSt8ios_base4InitC1Ev(ptr noundef nonnull align 1 dereferenceable(1) @_ZStL8__ioinit)
  %1 = call i32 @__cxa_atexit(ptr @_ZNSt8ios_base4InitD1Ev, ptr @_ZStL8__ioinit, ptr @__dso_handle) #3
  ret void
}

declare void @_ZNSt8ios_base4InitC1Ev(ptr noundef nonnull align 1 dereferenceable(1)) unnamed_addr #1

; Function Attrs: nounwind
declare void @_ZNSt8ios_base4InitD1Ev(ptr noundef nonnull align 1 dereferenceable(1)) unnamed_addr #2

; Function Attrs: nounwind
declare i32 @__cxa_atexit(ptr, ptr, ptr) #3

; Function Attrs: mustprogress noinline optnone uwtable
define dso_local void @_Z5debugPKcz(ptr noundef %0, ...) #4 {
  %2 = alloca ptr, align 8
  %3 = alloca [1 x %struct.__va_list_tag], align 16
  store ptr %0, ptr %2, align 8
  %4 = getelementptr inbounds [1 x %struct.__va_list_tag], ptr %3, i64 0, i64 0
  call void @llvm.va_start(ptr %4)
  %5 = call i32 (ptr, ...) @printf(ptr noundef @.str)
  %6 = load ptr, ptr %2, align 8
  %7 = getelementptr inbounds [1 x %struct.__va_list_tag], ptr %3, i64 0, i64 0
  %8 = call i32 @vprintf(ptr noundef %6, ptr noundef %7)
  %9 = getelementptr inbounds [1 x %struct.__va_list_tag], ptr %3, i64 0, i64 0
  call void @llvm.va_end(ptr %9)
  %10 = call i32 (ptr, ...) @printf(ptr noundef @.str.1)
  ret void
}

; Function Attrs: nocallback nofree nosync nounwind willreturn
declare void @llvm.va_start(ptr) #5

declare i32 @printf(ptr noundef, ...) #1

declare i32 @vprintf(ptr noundef, ptr noundef) #1

; Function Attrs: nocallback nofree nosync nounwind willreturn
declare void @llvm.va_end(ptr) #5

; Function Attrs: mustprogress noinline norecurse optnone uwtable
define dso_local noundef i32 @main() #6 {
  %1 = alloca i32, align 4
  %2 = alloca %class.Pointer, align 8
  %3 = alloca %class.Pointer, align 8
  %4 = alloca %class.Pointer, align 8
  %5 = alloca i64, align 8
  %6 = alloca %class.Pointer, align 8
  store i32 0, ptr %1, align 4
  %7 = call { ptr, i64 } @_Z8make_ptrIiE7PointerIT_Em(i64 noundef 1)
  %8 = getelementptr inbounds { ptr, i64 }, ptr %2, i32 0, i32 0
  %9 = extractvalue { ptr, i64 } %7, 0
  store ptr %9, ptr %8, align 8
  %10 = getelementptr inbounds { ptr, i64 }, ptr %2, i32 0, i32 1
  %11 = extractvalue { ptr, i64 } %7, 1
  store i64 %11, ptr %10, align 8
  call void @_ZN7PointerIiE5writeEi(ptr noundef nonnull align 8 dereferenceable(16) %2, i32 noundef 5)
  %12 = call noundef i32 @_ZN7PointerIiEdeEv(ptr noundef nonnull align 8 dereferenceable(16) %2)
  %13 = call noundef nonnull align 8 dereferenceable(8) ptr @_ZNSolsEi(ptr noundef nonnull align 8 dereferenceable(8) @_ZSt4cout, i32 noundef %12)
  %14 = call noundef nonnull align 8 dereferenceable(8) ptr @_ZNSolsEPFRSoS_E(ptr noundef nonnull align 8 dereferenceable(8) %13, ptr noundef @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
  call void @_ZN7PointerIiE7deallocEv(ptr noundef nonnull align 8 dereferenceable(16) %2)
  call void @_ZN7PointerIiE5allocEm(ptr noundef nonnull align 8 dereferenceable(16) %2, i64 noundef 3)
  call void @_ZN7PointerIiE5writeEi(ptr noundef nonnull align 8 dereferenceable(16) %2, i32 noundef 7)
  %15 = call { ptr, i64 } @_ZN7PointerIiEplEj(ptr noundef nonnull align 8 dereferenceable(16) %2, i32 noundef 1)
  %16 = getelementptr inbounds { ptr, i64 }, ptr %3, i32 0, i32 0
  %17 = extractvalue { ptr, i64 } %15, 0
  store ptr %17, ptr %16, align 8
  %18 = getelementptr inbounds { ptr, i64 }, ptr %3, i32 0, i32 1
  %19 = extractvalue { ptr, i64 } %15, 1
  store i64 %19, ptr %18, align 8
  call void @_ZN7PointerIiE5writeEi(ptr noundef nonnull align 8 dereferenceable(16) %3, i32 noundef 3)
  %20 = call { ptr, i64 } @_ZN7PointerIiEplEj(ptr noundef nonnull align 8 dereferenceable(16) %2, i32 noundef 2)
  %21 = getelementptr inbounds { ptr, i64 }, ptr %4, i32 0, i32 0
  %22 = extractvalue { ptr, i64 } %20, 0
  store ptr %22, ptr %21, align 8
  %23 = getelementptr inbounds { ptr, i64 }, ptr %4, i32 0, i32 1
  %24 = extractvalue { ptr, i64 } %20, 1
  store i64 %24, ptr %23, align 8
  call void @_ZN7PointerIiE5writeEi(ptr noundef nonnull align 8 dereferenceable(16) %4, i32 noundef 4)
  store i64 0, ptr %5, align 8
  br label %25

25:                                               ; preds = %39, %0
  %26 = load i64, ptr %5, align 8
  %27 = icmp ult i64 %26, 3
  br i1 %27, label %28, label %42

28:                                               ; preds = %25
  %29 = load i64, ptr %5, align 8
  %30 = trunc i64 %29 to i32
  %31 = call { ptr, i64 } @_ZN7PointerIiEplEj(ptr noundef nonnull align 8 dereferenceable(16) %2, i32 noundef %30)
  %32 = getelementptr inbounds { ptr, i64 }, ptr %6, i32 0, i32 0
  %33 = extractvalue { ptr, i64 } %31, 0
  store ptr %33, ptr %32, align 8
  %34 = getelementptr inbounds { ptr, i64 }, ptr %6, i32 0, i32 1
  %35 = extractvalue { ptr, i64 } %31, 1
  store i64 %35, ptr %34, align 8
  %36 = call noundef i32 @_ZN7PointerIiE4readEv(ptr noundef nonnull align 8 dereferenceable(16) %6)
  %37 = call noundef nonnull align 8 dereferenceable(8) ptr @_ZNSolsEi(ptr noundef nonnull align 8 dereferenceable(8) @_ZSt4cout, i32 noundef %36)
  %38 = call noundef nonnull align 8 dereferenceable(8) ptr @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(ptr noundef nonnull align 8 dereferenceable(8) %37, ptr noundef @.str.2)
  br label %39

39:                                               ; preds = %28
  %40 = load i64, ptr %5, align 8
  %41 = add i64 %40, 1
  store i64 %41, ptr %5, align 8
  br label %25, !llvm.loop !6

42:                                               ; preds = %25
  %43 = call noundef nonnull align 8 dereferenceable(8) ptr @_ZNSolsEPFRSoS_E(ptr noundef nonnull align 8 dereferenceable(8) @_ZSt4cout, ptr noundef @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
  call void @_ZN7PointerIiE7deallocEv(ptr noundef nonnull align 8 dereferenceable(16) %2)
  ret i32 0
}

; Function Attrs: mustprogress noinline optnone uwtable
define linkonce_odr dso_local { ptr, i64 } @_Z8make_ptrIiE7PointerIT_Em(i64 noundef %0) #4 comdat {
  %2 = alloca %class.Pointer, align 8
  %3 = alloca i64, align 8
  store i64 %0, ptr %3, align 8
  call void @_ZN7PointerIiEC2Ev(ptr noundef nonnull align 8 dereferenceable(16) %2)
  %4 = load i64, ptr %3, align 8
  call void @_ZN7PointerIiE5allocEm(ptr noundef nonnull align 8 dereferenceable(16) %2, i64 noundef %4)
  %5 = load { ptr, i64 }, ptr %2, align 8
  ret { ptr, i64 } %5
}

; Function Attrs: mustprogress noinline optnone uwtable
define linkonce_odr dso_local void @_ZN7PointerIiE5writeEi(ptr noundef nonnull align 8 dereferenceable(16) %0, i32 noundef %1) #4 comdat align 2 {
  %3 = alloca ptr, align 8
  %4 = alloca i32, align 4
  store ptr %0, ptr %3, align 8
  store i32 %1, ptr %4, align 4
  %5 = load ptr, ptr %3, align 8
  call void @_ZN7PointerIiE13error_on_nullEv(ptr noundef nonnull align 8 dereferenceable(16) %5)
  %6 = getelementptr inbounds %class.Pointer, ptr %5, i32 0, i32 1
  %7 = load i64, ptr %6, align 8
  %8 = getelementptr inbounds %class.Pointer, ptr %5, i32 0, i32 0
  %9 = load ptr, ptr %8, align 8
  call void (ptr, ...) @_Z5debugPKcz(ptr noundef @.str.3, i64 noundef %7, ptr noundef %9)
  %10 = load i32, ptr %4, align 4
  %11 = getelementptr inbounds %class.Pointer, ptr %5, i32 0, i32 0
  %12 = load ptr, ptr %11, align 8
  store i32 %10, ptr %12, align 4
  ret void
}

declare noundef nonnull align 8 dereferenceable(8) ptr @_ZNSolsEi(ptr noundef nonnull align 8 dereferenceable(8), i32 noundef) #1

; Function Attrs: mustprogress noinline optnone uwtable
define linkonce_odr dso_local noundef i32 @_ZN7PointerIiEdeEv(ptr noundef nonnull align 8 dereferenceable(16) %0) #4 comdat align 2 {
  %2 = alloca ptr, align 8
  store ptr %0, ptr %2, align 8
  %3 = load ptr, ptr %2, align 8
  call void @_ZN7PointerIiE13error_on_nullEv(ptr noundef nonnull align 8 dereferenceable(16) %3)
  %4 = getelementptr inbounds %class.Pointer, ptr %3, i32 0, i32 0
  %5 = load ptr, ptr %4, align 8
  %6 = load i32, ptr %5, align 4
  ret i32 %6
}

declare noundef nonnull align 8 dereferenceable(8) ptr @_ZNSolsEPFRSoS_E(ptr noundef nonnull align 8 dereferenceable(8), ptr noundef) #1

declare noundef nonnull align 8 dereferenceable(8) ptr @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(ptr noundef nonnull align 8 dereferenceable(8)) #1

; Function Attrs: mustprogress noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN7PointerIiE7deallocEv(ptr noundef nonnull align 8 dereferenceable(16) %0) #7 comdat align 2 {
  %2 = alloca ptr, align 8
  store ptr %0, ptr %2, align 8
  %3 = load ptr, ptr %2, align 8
  %4 = getelementptr inbounds %class.Pointer, ptr %3, i32 0, i32 0
  %5 = load ptr, ptr %4, align 8
  %6 = icmp ne ptr %5, null
  br i1 %6, label %7, label %13

7:                                                ; preds = %1
  %8 = getelementptr inbounds %class.Pointer, ptr %3, i32 0, i32 0
  %9 = load ptr, ptr %8, align 8
  %10 = icmp eq ptr %9, null
  br i1 %10, label %12, label %11

11:                                               ; preds = %7
  call void @_ZdaPv(ptr noundef %9) #12
  br label %12

12:                                               ; preds = %11, %7
  br label %13

13:                                               ; preds = %12, %1
  %14 = getelementptr inbounds %class.Pointer, ptr %3, i32 0, i32 0
  store ptr null, ptr %14, align 8
  ret void
}

; Function Attrs: mustprogress noinline optnone uwtable
define linkonce_odr dso_local void @_ZN7PointerIiE5allocEm(ptr noundef nonnull align 8 dereferenceable(16) %0, i64 noundef %1) #4 comdat align 2 {
  %3 = alloca ptr, align 8
  %4 = alloca i64, align 8
  store ptr %0, ptr %3, align 8
  store i64 %1, ptr %4, align 8
  %5 = load ptr, ptr %3, align 8
  %6 = getelementptr inbounds %class.Pointer, ptr %5, i32 0, i32 0
  %7 = load ptr, ptr %6, align 8
  %8 = icmp eq ptr %7, null
  br i1 %8, label %9, label %28

9:                                                ; preds = %2
  %10 = getelementptr inbounds %class.Pointer, ptr %5, i32 0, i32 1
  %11 = load i64, ptr %10, align 8
  %12 = load i64, ptr %4, align 8
  %13 = getelementptr inbounds %class.Pointer, ptr %5, i32 0, i32 0
  %14 = load ptr, ptr %13, align 8
  call void (ptr, ...) @_Z5debugPKcz(ptr noundef @.str.6, i64 noundef %11, i64 noundef %12, ptr noundef %14)
  %15 = load i64, ptr %4, align 8
  %16 = call { i64, i1 } @llvm.umul.with.overflow.i64(i64 %15, i64 4)
  %17 = extractvalue { i64, i1 } %16, 1
  %18 = extractvalue { i64, i1 } %16, 0
  %19 = select i1 %17, i64 -1, i64 %18
  %20 = call noalias noundef nonnull ptr @_Znam(i64 noundef %19) #13
  %21 = getelementptr inbounds %class.Pointer, ptr %5, i32 0, i32 0
  store ptr %20, ptr %21, align 8
  %22 = load i64, ptr %4, align 8
  %23 = getelementptr inbounds %class.Pointer, ptr %5, i32 0, i32 1
  store i64 %22, ptr %23, align 8
  %24 = getelementptr inbounds %class.Pointer, ptr %5, i32 0, i32 0
  %25 = load ptr, ptr %24, align 8
  %26 = getelementptr inbounds %class.Pointer, ptr %5, i32 0, i32 1
  %27 = load i64, ptr %26, align 8
  call void (ptr, ...) @_Z5debugPKcz(ptr noundef @.str.7, ptr noundef %25, i64 noundef %27)
  br label %28

28:                                               ; preds = %9, %2
  ret void
}

; Function Attrs: mustprogress noinline optnone uwtable
define linkonce_odr dso_local { ptr, i64 } @_ZN7PointerIiEplEj(ptr noundef nonnull align 8 dereferenceable(16) %0, i32 noundef %1) #4 comdat align 2 {
  %3 = alloca %class.Pointer, align 8
  %4 = alloca ptr, align 8
  %5 = alloca i32, align 4
  store ptr %0, ptr %4, align 8
  store i32 %1, ptr %5, align 4
  %6 = load ptr, ptr %4, align 8
  %7 = getelementptr inbounds %class.Pointer, ptr %6, i32 0, i32 1
  %8 = load i64, ptr %7, align 8
  %9 = load i32, ptr %5, align 4
  %10 = zext i32 %9 to i64
  %11 = icmp ule i64 %8, %10
  br i1 %11, label %12, label %14

12:                                               ; preds = %2
  %13 = call noundef nonnull align 8 dereferenceable(8) ptr @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(ptr noundef nonnull align 8 dereferenceable(8) @_ZSt4cout, ptr noundef @.str.8)
  call void @exit(i32 noundef 1) #14
  unreachable

14:                                               ; preds = %2
  %15 = getelementptr inbounds %class.Pointer, ptr %6, i32 0, i32 0
  %16 = load ptr, ptr %15, align 8
  %17 = load i32, ptr %5, align 4
  %18 = zext i32 %17 to i64
  %19 = getelementptr inbounds i32, ptr %16, i64 %18
  %20 = getelementptr inbounds %class.Pointer, ptr %6, i32 0, i32 1
  %21 = load i64, ptr %20, align 8
  %22 = load i32, ptr %5, align 4
  %23 = zext i32 %22 to i64
  %24 = sub i64 %21, %23
  call void @_ZN7PointerIiEC2EPim(ptr noundef nonnull align 8 dereferenceable(16) %3, ptr noundef %19, i64 noundef %24)
  %25 = load { ptr, i64 }, ptr %3, align 8
  ret { ptr, i64 } %25
}

declare noundef nonnull align 8 dereferenceable(8) ptr @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(ptr noundef nonnull align 8 dereferenceable(8), ptr noundef) #1

; Function Attrs: mustprogress noinline optnone uwtable
define linkonce_odr dso_local noundef i32 @_ZN7PointerIiE4readEv(ptr noundef nonnull align 8 dereferenceable(16) %0) #4 comdat align 2 {
  %2 = alloca ptr, align 8
  store ptr %0, ptr %2, align 8
  %3 = load ptr, ptr %2, align 8
  call void @_ZN7PointerIiE13error_on_nullEv(ptr noundef nonnull align 8 dereferenceable(16) %3)
  %4 = getelementptr inbounds %class.Pointer, ptr %3, i32 0, i32 0
  %5 = load ptr, ptr %4, align 8
  %6 = load i32, ptr %5, align 4
  ret i32 %6
}

; Function Attrs: mustprogress noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN7PointerIiEC2Ev(ptr noundef nonnull align 8 dereferenceable(16) %0) unnamed_addr #7 comdat align 2 {
  %2 = alloca ptr, align 8
  store ptr %0, ptr %2, align 8
  %3 = load ptr, ptr %2, align 8
  %4 = getelementptr inbounds %class.Pointer, ptr %3, i32 0, i32 0
  store ptr null, ptr %4, align 8
  %5 = getelementptr inbounds %class.Pointer, ptr %3, i32 0, i32 1
  store i64 0, ptr %5, align 8
  ret void
}

; Function Attrs: mustprogress noinline optnone uwtable
define linkonce_odr dso_local void @_ZN7PointerIiE13error_on_nullEv(ptr noundef nonnull align 8 dereferenceable(16) %0) #4 comdat align 2 {
  %2 = alloca ptr, align 8
  store ptr %0, ptr %2, align 8
  %3 = load ptr, ptr %2, align 8
  %4 = getelementptr inbounds %class.Pointer, ptr %3, i32 0, i32 0
  %5 = load ptr, ptr %4, align 8
  %6 = icmp eq ptr %5, null
  br i1 %6, label %7, label %10

7:                                                ; preds = %1
  %8 = call noundef nonnull align 8 dereferenceable(8) ptr @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(ptr noundef nonnull align 8 dereferenceable(8) @_ZSt4cout, ptr noundef @.str.4)
  %9 = call noundef nonnull align 8 dereferenceable(8) ptr @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(ptr noundef nonnull align 8 dereferenceable(8) %8, ptr noundef @.str.5)
  call void @exit(i32 noundef 1) #14
  unreachable

10:                                               ; preds = %1
  ret void
}

; Function Attrs: noreturn nounwind
declare void @exit(i32 noundef) #8

; Function Attrs: nobuiltin nounwind
declare void @_ZdaPv(ptr noundef) #9

; Function Attrs: nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare { i64, i1 } @llvm.umul.with.overflow.i64(i64, i64) #10

; Function Attrs: nobuiltin allocsize(0)
declare noundef nonnull ptr @_Znam(i64 noundef) #11

; Function Attrs: mustprogress noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN7PointerIiEC2EPim(ptr noundef nonnull align 8 dereferenceable(16) %0, ptr noundef %1, i64 noundef %2) unnamed_addr #7 comdat align 2 {
  %4 = alloca ptr, align 8
  %5 = alloca ptr, align 8
  %6 = alloca i64, align 8
  store ptr %0, ptr %4, align 8
  store ptr %1, ptr %5, align 8
  store i64 %2, ptr %6, align 8
  %7 = load ptr, ptr %4, align 8
  %8 = getelementptr inbounds %class.Pointer, ptr %7, i32 0, i32 0
  %9 = load ptr, ptr %5, align 8
  store ptr %9, ptr %8, align 8
  %10 = getelementptr inbounds %class.Pointer, ptr %7, i32 0, i32 1
  %11 = load i64, ptr %6, align 8
  store i64 %11, ptr %10, align 8
  ret void
}

; Function Attrs: noinline uwtable
define internal void @_GLOBAL__sub_I_ptr.cpp() #0 section ".text.startup" {
  call void @__cxx_global_var_init()
  ret void
}

attributes #0 = { noinline uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { nounwind }
attributes #4 = { mustprogress noinline optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #5 = { nocallback nofree nosync nounwind willreturn }
attributes #6 = { mustprogress noinline norecurse optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #7 = { mustprogress noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #8 = { noreturn nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #9 = { nobuiltin nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #10 = { nocallback nofree nosync nounwind speculatable willreturn memory(none) }
attributes #11 = { nobuiltin allocsize(0) "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #12 = { builtin nounwind }
attributes #13 = { builtin allocsize(0) }
attributes #14 = { noreturn nounwind }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 18.1.8 (++20240731024944+3b5b5c1ec4a3-1~exp1~20240731145000.144)"}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
