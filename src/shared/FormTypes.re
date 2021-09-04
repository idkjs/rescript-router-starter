/*
 This file hold the types we are using in our UseForm.re form hook and in the the Form pages themselves.
 `formState` defines the input state for our input fields in the forms.
 `formRules` defines state for our form validation rules
  */
type formState = {
  username: string,
  email: string,
  password: string,
};
/* We will have a fixed number of rules, and we will have to map over all of them. Arrays are a good fit because they have a fixed size. We could use a List, which is an immutable singly-linked list under the hood. But finding an element is O(n) for both Lists and Arrays, and Arrays are a better fit for sets of items of known size.
   The Ocaml [website](https://ocaml.org/learn/tutorials/comparison_of_standard_containers.html) offers a concise overview of the different standard containers.
   */
type formRule = {
  id: int,
  field: string,
  message: string,
  valid: bool,
};

type formRules = array(formRule);

type formType =
  | Register
  | Login;
